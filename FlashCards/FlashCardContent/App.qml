import QtQuick
import QtQuick.Controls
import FlashCard

Window {
    width: Constants.width  // Certifique-se de que Constants está definido
    height: Constants.height
    visible: true
    title: "FlashCard"

    // StackView para gerenciar a navegação
    StackView {
        id: stackView
        anchors.fill: parent
        initialItem: TelaInicio {}  // Define TelaInicio como a primeira tela
    }
}
