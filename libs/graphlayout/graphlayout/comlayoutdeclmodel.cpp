                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             #include "comlayoutdeclmodel.hpp"

#include <mobata/model/spenat/spenatdeclmodel.hpp>
#include <mobata/model/spenat/placeitem.hpp>
#include <mobata/model/spenat/transitionitem.hpp>
#include <mobata/model/spenat/junctionitem.hpp>
#include <mobata/model/spenat/junctionarc.hpp>
#include <mobata/model/spenat/junctionarc.hpp>
#include <mobata/model/spenat/preplacearc.hpp>
#include <mobata/model/spenat/postplacearc.hpp>

#include <mobatawidgets/spenat/declplace.hpp>
#include <mobatawidgets/spenat/decltransition.hpp>
#include <mobatawidgets/spenat/decljunction.hpp>
#include <mobatawidgets/spenat/declscene.hpp>

#include "comlayoutgraphscene.hpp"

#include <QDir>
#include <QDebug>

#include <chrono>

#include <mobata/memory_leak_start.hpp>

using namespace model::spenat;
using namespace view::graph;
using namespace view::spenat;

using namespace graphlayout;

class ComLayoutDeclModel::Private
{
    friend class ComLayoutDeclModel;

    SpenatDeclModel const*  _declModel;
    DeclScene*        _declScene;
    const QDir        _graphvizBinDir;
    int               _offset;
    int               _step;

    Private(SpenatDeclModel const* declModel,
            DeclScene* declScene,
            const QDir &graphvizBinDir)
        : _declModel(declModel),
          _declScene(declScene),
          _graphvizBinDir(graphvizBinDir),
          _offset(10), _step(1)
    {}

    void updateDeclScene();
};

void ComLayoutDeclModel::Private::updateDeclScene()
{
    Q_ASSERT(this->_declModel);
    Q_ASSERT(this->_declScene);

    foreach(PlaceItem const* modelPlace,
            this->_declModel->places())
    {
        DeclPlace const* declPlace=this->_declScene->place(modelPlace->uuid());
        if(declPlace)
            continue;

        declPlace=this->_declScene->addPlace(QPointF(this->_offset*this->_step,
                                                     this->_offset*this->_step),
                                             modelPlace->toString(),
                                             modelPlace->uuid());
        ++this->_step;

        if(this->_declModel->isInitPlace(modelPlace))
        {
            const_cast<DeclPlace*>(declPlace)->setInitMarking(true);
            const_cast<DeclPlace*>(declPlace)->setMarking(true);
        }
    }

    foreach(TransitionItem const* modelTransition,
            this->_declModel->transitions())
    {
        TransitionItem::ConstPrePlaceArcSet prePlaceArcs = modelTransition->prePlaceArcs();
        TransitionItem::ConstPostPlaceArcSet postPlaceArcs = modelTransition->postPlaceArcs();

        if(prePlaceArcs.size() == 1
                && postPlaceArcs.size() == 1)//arc-transition
        {
            DeclArc const* declArc=this->_declScene->arc(modelTransition->uuid());
            if(declArc)
                continue;

            Q_ASSERT(prePlaceArcs.at(0));
            Q_ASSERT(prePlaceArcs.at(0)->place());
            DeclPlace* declPrePlace=this->_declScene->place(prePlaceArcs.at(0)->place()->uuid());
            Q_ASSERT(declPrePlace);

            Q_ASSERT(postPlaceArcs.at(0));
            Q_ASSERT(postPlaceArcs.at(0)->place());
            DeclPlace* declPostPlace=this->_declScene->place(postPlaceArcs.at(0)->place()->uuid());
            Q_ASSERT(declPostPlace);

            declArc=this->_declScene->addArc(declPrePlace,
                                             declPostPlace,
                                             modelTransition->toString(),
                                             modelTransition->uuid());
        }
        else
        {
            DeclTransition* declTransition=this->_declScene->transition(modelTransition->uuid());
            if(declTransition)
                continue;

            declTransition=this->_declScene->addTransition(QPointF(this->_offset*this->_step,
                                                                   this->_offset*this->_step),
                                                           modelTransition->toString(),
                                                           modelTransition->uuid());
            ++this->_step;

            ///pre-place-arcs////////////////
            foreach(PrePlaceArc const* prePlaceArc, prePlaceArcs)
            {
                DeclArc const* declArc=this->_declScene->arc(prePlaceArc->uuid());
                if(declArc)
                    continue;

                Q_ASSERT(prePlaceArc->place());
                DeclPlace* declPrePlace=this->_declScene->place(prePlaceArc->place()->uuid());
                Q_ASSERT(declPrePlace);

                declArc=this->_declScene->addArc(declPrePlace,
                                                 declTransition,
                                                 QStringLiteral(""),
                                                 prePlaceArc->uuid());
            }

            ///post-place-arcs////////////////
            foreach(PostPlaceArc const* postPlaceArc, postPlaceArcs)
            {
                DeclArc const* declArc=this->_declScene->arc(postPlaceArc->uuid());
                if(declArc)
                    continue;

                Q_ASSERT(postPlaceArc->place());
                DeclPlace* declPostPlace=this->_declScene->place(postPlaceArc->place()->uuid());
                Q_ASSERT(declPostPlace);

                declArc=this->_declScene->addArc(declTransition,
                                                 declPostPlace,
                                                 QStringLiteral(""),
                                                 postPlaceArc->uuid());
            }
        }
    }

    //first junction nodes///
    foreach(JunctionItem const* modelJunction,
            this->_declModel->junctions())
    {
        DeclJunction const* declJunction=this->_declScene->junction(modelJunction->uuid());
        if(declJunction)
            continue;

        declJunction=this->_declScene->addJunction(QPointF(this->_offset*this->_step,
                                                           this->_offset*this->_step),
                                                   modelJunction->uuid());
        ++this->_step;
    }

    //now junction arcs///
    foreach(JunctionItem const* modelJunction,
            this->_declModel->junctions())
    {
        DeclJunction* declJunction = this->_declScene->junction(modelJunction->uuid());
        Q_ASSERT(declJunction);

        //junction sources//
        foreach(JunctionArc const* junctionSource,
                modelJunction->sources())
        {
            DeclArc const* declArc=this->_declScene->arc(junctionSource->uuid());
            if(declArc)
                continue;

            Q_ASSERT(junctionSource->source());
            AbstractNode* declNode=this->_declScene->node(junctionSource->source()->uuid());
            Q_ASSERT(declNode);

            declArc=this->_declScene->addArc(declNode,
                                             declJunction,
                                             junctionSource->toString(),
                                             junctionSource->uuid());
        }

        //junction targets//
        foreach(JunctionArc const* junctionTarget,
                modelJunction->targets())
        {
            DeclArc const* declArc=this->_declScene->arc(junctionTarget->uuid());
            if(declArc)
                continue;

            Q_ASSERT(junctionTarget->target());
            AbstractNode* declNode=this->_declScene->node(junctionTarget->target()->uuid());
            Q_ASSERT(declNode);

            declArc=this->_declScene->addArc(declJunction,
                                             declNode,
                                             junctionTarget->toString(),
                                             junctionTarget->uuid());
        }
    }

    return;
}

ComLayoutDeclModel::ComLayoutDeclModel(SpenatDeclModel const* declModel,
                                       DeclScene* declScene,
                                       const QDir &graphvizBinDir)
    : _d(new Private(declModel, declScene, graphvizBinDir))
{}

ComLayoutDeclModel::~ComLayoutDeclModel()
{
    delete this->_d;
}

bool ComLayoutDeclModel::execute(QString* errorString)
{
    Q_ASSERT(this->_d->_declModel);
    Q_ASSERT(this->_d->_declScene);

    auto start = std::chrono::steady_clock::now();

    this->_d->_declScene->reset();
    this->_d->updateDeclScene();

    ComLayoutGraphScene layoutGraphSceneCommand(this->_d->_declScene,
                                                this->_d->_graphvizBinDir);
    bool result = layoutGraphSceneCommand.execute(errorString);

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start);
    qDebug() << "layout decl model time: " << duration.count() / 1000.0 << " ms";

    return result;
}
