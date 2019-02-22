# Mobata 

**Mobata** (Model Based Test Automation) is a library of modelling languages implemented in c++ for specification models including:
- [UML Statemachines](https://en.wikipedia.org/wiki/UML_state_machine)
- [Message Sequence Charts](https://en.wikipedia.org/wiki/Message_sequence_chart)
- Requirement Models
- SPENAT - Secure Petri Net with Attributes

The grammars of each modelling language is defined using [ANTLR v4](https://github.com/antlr/antlr4)

## Authors and major contributors
- [ifak] (https://www.ifak.eu)
Institut für Automation und Kommunikation - Mobata project lead
- [...]

## Prerequisites
- [Visual Studio](https://www.visualstudio.com/vs/community/) (VS 2015 recommended)
- [Qt](https://www.qt.io/) (Qt LTS 5.12 recommended)

## Contributing to Mobata
Please follow these steps to contribute to mobata:
1. Fork the ifak/mobata repo
2. Build mobata using latest Qt LTS (Currently 5.12 - https://www.qt.io/)
3. Run the mobata unit tests (see **Running Unit Tests** below)
4. Sign the **contributors.txt** if you've not done so before.
5. Create a pull request including your change

## Running Unit Tests
All Unit Tests in mobata are implemented using [Qt Test framework](https://doc.qt.io/qt-5/qttest-index.html).
It is recommended to run all units tests using the QtCreator, an IDE developed by Qt. QtCreators gives an overview of all existing unit tests implemented using Qt Test. They can also be run individually by selecting them using the checkbox:

![Select Tests](/images/select_tests.jpg)

The test execution can then be started for all unit tests, the selected unit tests or the unit tests of the current file using the respective run button: 

![Run Tests](/images/run_tests.jpg)

Alternatively, it is possible to run the tests by starting the executable generated for each test script or by running nmake check in the build directory using a console.

## License
Mobata is open source software licensed under the [LGPLv3](https://github.com/ifak/mobata/blob/master/LICENSE). Have an overview of the license [here](https://tldrlegal.com/license/gnu-lesser-general-public-license-v3-(lgpl-3))



