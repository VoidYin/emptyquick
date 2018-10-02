import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Window {
    visible: true
    width: 320
    height: 480
    title: qsTr("Hello World")

    TestListView {
        id: testListView
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: addBtn.top
    }

    RoundButton {
        id: addBtn
        text: "+"
        anchors.horizontalCenter : parent.horizontalCenter
        anchors.bottom: parent.bottom
        onClicked: {
            console.log("addbtn clicked");
        }
    }
}
