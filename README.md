# Mobata 

**Mobata** (Model Based Test Automation) is a library of modelling languages implemented in c++ for specification models including:
- [UML Statemachines](https://en.wikipedia.org/wiki/UML_state_machine)
- [Message Sequence Charts](https://en.wikipedia.org/wiki/Message_sequence_chart)
- Requirement Models
- High-Level Petri Nets like SPENAT - Safe Petri Net with Attributes

The grammars of each modelling language are defined using [ANTLR v4](https://github.com/antlr/antlr4), which is part of mobata (v.4.7.2)

## Authors and major contributors
- [ifak] (https://www.ifak.eu)
Institut für Automation und Kommunikation - Mobata project lead
- [...]

## Prerequisites
- [Qt](https://www.qt.io/) (Qt LTS 5.12 recommended)

## Contributing to Mobata
Please follow these steps to contribute to mobata:
1. Fork the ifak/mobata repo
2. Build mobata using latest Qt LTS (Currently 5.12 - https://www.qt.io/)
3. Run the mobata unit tests (see **Running Unit Tests** below)
4. Create a pull request including your change

## Running Unit Tests
All Unit Tests in mobata are implemented using [Qt Test framework](https://doc.qt.io/qt-5/qttest-index.html).
It is recommended to run all units tests using the QtCreator, an IDE developed by Qt:
- [Running Tests in QtCreator](https://doc.qt.io/qtcreator/creator-autotest.html#building-and-running-tests)

Alternatively, it is possible to run the tests by starting the executable generated for each test script or by running *nmake check* in the build directory using a console.

## License
Mobata is open source software licensed under the [LGPLv3](https://github.com/ifak/mobata/blob/master/LICENSE).



