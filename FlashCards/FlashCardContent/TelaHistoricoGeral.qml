

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

    // Função para navegar para outra tela
    function navigateTo(page) {
        if (stackView) {  // Verifica se o StackView está disponível
            stackView.push(page + ".qml");
        }
    }

    Rectangle {
        id: rectangle
        x: 0
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

            onClicked: navigateTo("TelaInicio")
        }
    }

    Image {
        id: home2
        x: 37
        y: 43
        source: "../images/home 2.png"
        fillMode: Image.PreserveAspectFit
    }

    Rectangle {
        id: rectangle1D9D9D9
        x: 155
        y: 441
        width: 1610
        height: 100
        color: "#d9d9d9"
    }

    Rectangle {
        id: rectangle1D9D9D10
        x: 155
        y: 565
        width: 1610
        height: 100
        color: "#d9d9d9"
    }

    Rectangle {
        id: rectangle1D9D9D11
        x: 155
        y: 685
        width: 1610
        height: 100
        color: "#d9d9d9"
    }

    Rectangle {
        id: rectangle1D9D9D12
        x: 155
        y: 806
        width: 1610
        height: 100
        color: "#d9d9d9"
    }

    Rectangle {
        id: rectangle1D9D9D13
        x: 155
        y: 322
        width: 1610
        height: 100
        color: "#d9d9d9"

        Text {
            id: text4
            x: 8
            y: 8
            width: 1594
            height: 84
            text: "Run 1 | Materia - Submateria  - 00/00 - 00:00"
            font.pixelSize: 64
            font.bold: true
            font.family: "Arial"

            Button {
                id: button
                x: 1510
                y: 8
                width: 76
                height: 76
            }

            Button {
                id: button1
                x: 1437
                y: 8
                width: 67
                height: 76

                Image {
                    id: image1
                    x: 0
                    y: -1
                    width: 76
                    height: 76
                    source: "../images/edit.png"
                    fillMode: Image.PreserveAspectFit
                }
            }
        }

        Image {
            id: image
            x: 1521
            y: 15
            width: 70
            height: 70
            source: "../images/lixo.png"
            fillMode: Image.PreserveAspectFit
        }

        Text {
            id: text5
            x: 8
            y: 130
            width: 1594
            height: 84
            text: "Run 2 | Materia - Submateria  - 00/00 - 00:00"
            font.pixelSize: 64
            font.family: "Arial"
            font.bold: true
            Button {
                id: button2
                x: 1510
                y: 8
                width: 76
                height: 76
            }

            Button {
                id: button3
                x: 1437
                y: 8
                width: 67
                height: 76
                Image {
                    id: image2
                    x: 0
                    y: -1
                    width: 76
                    height: 76
                    source: "../images/edit.png"
                    fillMode: Image.PreserveAspectFit
                }
            }
        }

        Image {
            id: image3
            x: 1521
            y: 144
            width: 70
            height: 70
            source: "../images/lixo.png"
            fillMode: Image.PreserveAspectFit
        }

        Text {
            id: text6
            x: 8
            y: 252
            width: 1594
            height: 84
            text: "Run 3 | Materia - Submateria  - 00/00 - 00:00"
            font.pixelSize: 64
            font.family: "Arial"
            font.bold: true
            Button {
                id: button4
                x: 1510
                y: 8
                width: 76
                height: 76
            }

            Button {
                id: button5
                x: 1437
                y: 8
                width: 67
                height: 76
                Image {
                    id: image4
                    x: 0
                    y: -1
                    width: 76
                    height: 76
                    source: "../images/edit.png"
                    fillMode: Image.PreserveAspectFit
                }
            }
        }

        Image {
            id: image5
            x: 1521
            y: 259
            width: 70
            height: 70
            source: "../images/lixo.png"
            fillMode: Image.PreserveAspectFit
        }

        Text {
            id: text7
            x: 8
            y: 379
            width: 1594
            height: 84
            text: "Run 4 | Materia - Submateria  - 00/00 - 00:00"
            font.pixelSize: 64
            font.family: "Arial"
            font.bold: true
            Button {
                id: button6
                x: 1510
                y: 8
                width: 76
                height: 76
            }

            Button {
                id: button7
                x: 1437
                y: 8
                width: 67
                height: 76
                Image {
                    id: image6
                    x: 0
                    y: -1
                    width: 76
                    height: 76
                    source: "../images/edit.png"
                    fillMode: Image.PreserveAspectFit
                }
            }
        }

        Image {
            id: image8
            x: 1521
            y: 386
            width: 70
            height: 70
            source: "../images/lixo.png"
            fillMode: Image.PreserveAspectFit
        }
    }

    Rectangle {
        id: rectangle1D9D9D14
        x: 155
        y: 175
        width: 1610
        height: 100
        color: "#d9d9d9"

        Text {
            id: text1
            x: 8
            y: 8
            width: 461
            height: 84
            text: "Ordenar por:"
            font.pixelSize: 64
            font.bold: true
            font.family: "Arial"
        }

        Text {
            id: text2
            x: 652
            y: 8
            width: 394
            height: 84
            text: qsTr("Acertos/Erros")
            font.pixelSize: 64
            font.family: "Arial"
        }

        Text {
            id: text3
            x: 1144
            y: 8
            width: 253
            height: 84
            text: qsTr("Tempo")
            font.pixelSize: 64
            font.family: "Arial"
        }
    }

    Text {
        id: text8
        x: 163
        y: 814
        width: 1594
        height: 84
        text: "Run 5 | Materia - Submateria  - 00/00 - 00:00"
        font.pixelSize: 64
        font.family: "Arial"
        font.bold: true
        Button {
            id: button8
            x: 1510
            y: 8
            width: 76
            height: 76
        }

        Button {
            id: button9
            x: 1437
            y: 8
            width: 67
            height: 76
            Image {
                id: image7
                x: 0
                y: -1
                width: 76
                height: 76
                source: "../images/edit.png"
                fillMode: Image.PreserveAspectFit
            }
        }
    }

    Image {
        id: image9
        x: 1687
        y: 821
        width: 70
        height: 70
        source: "../images/lixo.png"
        fillMode: Image.PreserveAspectFit
    }

    Item {
        id: __materialLibrary__
    }
}
