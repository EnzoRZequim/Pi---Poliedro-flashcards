import QtQuick
import QtQuick.Controls

Window {
    width: 1920
    height: 1080
    visible: true
    title: "FlashCard"

    // StackView para gerir a navegação
    StackView {
        id: stackView
        anchors.fill: parent
        initialItem: TelaInicio {}
    }
}
