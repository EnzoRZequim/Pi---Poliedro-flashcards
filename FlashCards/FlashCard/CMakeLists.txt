### This file is automatically generated by Qt Design Studio.
### Do not change

set_source_files_properties(Constants.qml
    PROPERTIES
        QT_QML_SINGLETON_TYPE true
)



qt_add_library(FlashCard STATIC)
qt6_add_qml_module(FlashCard
    URI "FlashCard"
    VERSION 1.0
    RESOURCE_PREFIX "/qt/qml"
    QML_FILES
        "EventListModel.qml"
        "Constants.qml"
        "EventListSimulator.qml"
)


