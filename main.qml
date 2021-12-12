import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

import VESTA.ClassNats 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("NATS Server example")

    ClassNats {
        id: classNats
        onSignalConnectNatsServer: textArea.append(message)
    }

    Row {
        id: row
        width: parent.width
        spacing: 5

        Button {
            width: 100
            height: 30
            text: "Send Message"
            onClicked: if(textField.text != "") { classNats.publishMessage(textField.text); textField.clear(); textField.forceActiveFocus() }
        }

        TextField {
            id: textField
            height: 30
            placeholderText: "Send message to NATS server ..."
        }
    }

    TextArea {
        id: textArea
        anchors { top: row.bottom; topMargin: 5;  }
        width: parent.width
        height: 300
        background: Rectangle { color: "#808080" }
        readOnly: true
    }
}
