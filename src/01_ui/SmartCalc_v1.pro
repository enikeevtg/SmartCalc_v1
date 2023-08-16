QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../02_data_structs_processing/fill_node.c \
    ../02_data_structs_processing/move_node.c \
    ../02_data_structs_processing/pop.c \
    ../02_data_structs_processing/push.c \
    ../02_data_structs_processing/remove_head_node.c \
    ../02_data_structs_processing/remove_struct.c \
    ../03_evaluations/01_convert_infix_to_RPN.c \
    ../03_evaluations/02_close_bracket_processing.c \
    ../03_evaluations/03_end_of_expression_processing.c \
    ../03_evaluations/04_token_processing.c \
    ../03_evaluations/05_container_packing.c \
    ../03_evaluations/06_create_mult.c \
    ../03_evaluations/07_container_sending.c \
    ../03_evaluations/08_evaluate_expression.c \
    ../03_evaluations/09_numerical_calculation.c \
    ../04_credit_calculator/credit_calculator.c \
    ../05_deposit_calculator/deposit_calculator.c \
    creditcalcwindow.cpp \
    depositcalcwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp

HEADERS += \
    ../04_credit_calculator/credit_calculator.h \
    ../05_deposit_calculator/deposit_calculator.h \
    ../data_structures.h \
    ../smart_calc.h \
    creditcalcwindow.h \
    depositcalcwindow.h \
    mainwindow.h \
    qcustomplot.h \

FORMS += \
    creditcalcwindow.ui \
    depositcalcwindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
