#include "comlayoutspenatmodel.hpp"

#include <mobata/model/spenat/spenatmodel.hpp>
#include <mobata/model/spenat/placeitem.hpp>
#include <mobata/model/spenat/transitionitem.hpp>
#include <mobata/model/spenat/preplacearc.hpp>
#include <mobata/model/spenat/postplacearc.hpp>

#include <mobatawidgets/spenat/declplace.hpp>
#include <mobatawidgets/spenat/decltransition.hpp>
#include <mobatawidgets/spenat/spenatscene.hpp>

#include "comlayoutgraphscene.hpp"

#include <QDir>

#include <mobata/memory_leak_start.hpp>

using namespace model::spenat;

using namespace view::spenat;

using namespace graphlayout;

class ComLayoutSpenatModel::Private
{
    friend class ComLayoutSpenatModel;

    Private(SpenatModel const* spenatModel,
            SpenatScene *spenatScene,
            const QDir &graphvizBinDir)
        : _spenatModel(spenatModel),
          _spenatScene(spenatScene),
          _graphvizBinDir(graphvizBinDir),
          _offset(10), _step(1)
    {}

    void updateSpenatScene();

    SpenatModel const*  _spenatModel;
    SpenatScene*        _spenatScene;
    const QDir          _graphvizBinDir;
    int                 _offset;
    int                 _step;
};

void ComLayoutSpenatModel::Private::updateSpenatScene()
{
    Q_ASSERT(this->_spenatModel);
    Q_ASSERT(this->_spenatScene);

    foreach(PlaceItem const* modelPlace,
            this->_spenatModel->places())
    {
        DeclPlace const* declPlace=this->_spenatScene->place(modelPlace->uuid());
        if(declPlace)
            continue;

        declPlace=this->_spenatScene->addPlace(QPointF(this->_offset*this->_step,
                                                       this->_offset*this->_step),
                                               modelPlace->toString(),
                                               modelPlace->uuid());
        ++this->_step;

        if(this->_spenatModel->isInitPlace(modelPlace))
        {
            const_cast<DeclPlace*>(declPlace)->setInitMarking(true);
            const_cast<DeclPlace*>(declPlace)->setMarking(true);
        }
    }

    foreach(TransitionItem const* modelTransition,
            this->_spenatModel->transitions())
    {
        DeclTransition* declTransition=this->_spenatScene->transition(modelTransition->uuid());
        if(declTransition)
            continue;

        declTransition=this->_spenatScene->addTransition(QPointF(this->_offset*this->_step,
                                                                 this->_offset*this->_step),
                                                         modelTransition->toString(),
                                                         modelTransition->uuid());
        ++this->_step;

        ///pre-place-arcs////////////////
        foreach(PrePlaceArc const* prePlaceArc,
                modelTransition->prePlaceArcs())
        {
            DeclArc const* declArc=this->_spenatScene->arc(prePlaceArc->uuid());
            if(declArc)
                continue;

            Q_ASSERT(prePlaceArc->place());
            DeclPlace* declPrePlace=this->_spenatScene->place(prePlaceArc->place()->uuid());
            Q_ASSERT(declPrePlace);

            declArc=this->_spenatScene->addArc(declPrePlace,
                                               declTransition,
                                               QStringLiteral(""),
                                               prePlaceArc->uuid());
        }

        ///post-place-arcs////////////////
        foreach(PostPlaceArc const* postPlaceArc,
                modelTransition->postPlaceArcs())
        {
            DeclArc const* declArc=this->_spenatScene->arc(postPlaceArc->uuid());
            if(declArc)
                continue;

            Q_ASSERT(postPlaceArc->place());
            DeclPlace* declPostPlace=this->_spenatScene->place(postPlaceArc->place()->uuid());
            Q_ASSERT(declPostPlace);

            declArc=this->_spenatScene->addArc(declTransition,
                                               declPostPlace,
                                               QStringLiteral(""),
                                               postPlaceArc->uuid());
        }
    }

    return;
}

ComLayoutSpenatModel::ComLayoutSpenatModel(SpenatModel const* spenatModel,
                                           SpenatScene *spenatScene,
                                           const QDir &graphvizBinDir)
    : _d(new Private(spenatModel, spenatScene, graphvizBinDir))
{}

ComLayoutSpenatModel::~ComLayoutSpenatModel()
{
    delete this->_d;
}

bool ComLayoutSpenatModel::execute(QString* errorString)
{
    Q_ASSERT(this->_d->_spenatModel);
    Q_ASSERT(this->_d->_spenatScene);

    this->_d->updateSpenatScene();

    ComLayoutGraphScene layoutGraphSceneCommand(this->_d->_spenatScene,
                                                this->_d->_graphvizBinDir);
    return layoutGraphSceneCommand.execute(errorString);
}
