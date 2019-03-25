import QtQuick 2.7
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.12

import Provide 1.0

ApplicationWindow {
    id: window
    title: "Example"
    visible: true
    height: 600
    width: 800

    Provide {
        id: provide
    }

    RowLayout {
        anchors.fill: parent

        ListView {
            Layout.fillWidth: true
            Layout.fillHeight: true

            currentIndex: count - 1
            model: provide.model
            delegate: Text {
                text: something.foo()
            }
        }
    }
}
