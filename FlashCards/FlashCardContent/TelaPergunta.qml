

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick
import QtQuick.Controls

Item {
    id: root
    width: 1920
    height: 1080

    property int flashcardId: -1

    // Propriedade para guardar o texto da pergunta
    property string perguntaTexto: ""

    Component.onCompleted: {
        // Ao carregar, busca a pergunta usando o ID recebido
        if (flashcardId !== -1) {
            perguntaTexto = ponte.selectPergunta(flashcardId);
        }
    }

    // Função para navegar para outra tela
    function navigateTo(page) {
        if (stackView) {  // Verifica se o StackView está disponível
            stackView.push(page + ".qml");
        }
    }

    Rectangle {
        id: rectangle
        x: -8
        y: 0
        width: 1920
        height: 1088
        color: "#ffffff"
        Button {
            id: btHome
            x: 29
            y: 42
            width: 133
            height: 114
            text: qsTr("")
            onClicked: { navigateTo("TelaInicio") }
        }

        Rectangle {
            id: rectangle2
            x: 1443
            y: 55
            width: 256
            height: 88
            color: "#d1d1d1"
            Text {
                id: timer
                x: 0
                y: 4
                width: 256
                height: 80
                text: qsTr("00:00")
                font.pixelSize: 64
                horizontalAlignment: Text.AlignHCenter
                font.weight: Font.Bold
            }
        }

        Rectangle {
            id: rectangle3
            x: 1102
            y: 55
            width: 256
            height: 88
            color: "#d1d1d1"
        }

        Text {
            id: quantidade
            x: 1102
            y: 59
            width: 256
            height: 80
            text: qsTr("0 / 1")
            font.pixelSize: 64
            horizontalAlignment: Text.AlignHCenter
            font.weight: Font.Bold
        }
    }

    Image {
        id: home2
        x: 29
        y: 43
        source: "../images/home 2.png"
        fillMode: Image.PreserveAspectFit
    }

    Rectangle {
        id: rectangle1
        x: 213
        y: 238
        width: 1478
        height: 665
        color: "#d1d1d1"
        Text {
            id: textoPergunta
            x: 8
            y: 8
            width: 1462
            height: 649
            text: perguntaTexto
            font.pixelSize: 64
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.styleName: "Semibold"
        }
    }

    Button {
        id: btVerResposta
        x: 1201
        y: 947
        width: 490
        height: 100
        text: qsTr("Ver Resposta")
        font.pointSize: 36
        font.family: "Arial"
        font.bold: true
        onClicked: {
            stackView.push("TelaResposta.qml", { "flashcardId": flashcardId });
        }
    }
}
