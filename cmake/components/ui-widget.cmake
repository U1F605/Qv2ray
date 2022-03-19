set(QVMESSOCKET_QWIDGETS_UI_BASEDIR ${CMAKE_SOURCE_DIR}/src/ui/widgets)
add_definitions(-DQAPPLICATION_CLASS=QApplication)

set(_QV2RAY_UI_FORMS
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/editors/w_OutboundEditor.ui
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/editors/w_InboundEditor.ui
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/editors/w_JsonEditor.ui
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/editors/w_RoutesEditor.ui
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/editors/w_ChainSha256Editor.ui
    #
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/widgets/StreamSettingsWidget.ui
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/widgets/ConnectionInfoWidget.ui
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/widgets/ConnectionItemWidget.ui
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/widgets/RouteSettingsMatrix.ui
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/widgets/InboundSettingsWidget.ui
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/widgets/ConnectionSettingsWidget.ui
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/widgets/DnsSettingsWidget.ui
    #
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/windows/w_GroupManager.ui
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/windows/w_ImportConfig.ui
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/windows/w_MainWindow.ui
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/windows/w_PreferencesWindow.ui
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/windows/w_PluginManager.ui
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/windows/w_ScreenShot_Core.ui
    #
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/widgets/complex/ChainEditorWidget.ui
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/widgets/complex/RoutingEditorWidget.ui
    )

set(_QVMESSOCKET_UI_NODEEDITOR_SOURCES
    # NodeEditor Models
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/node/NodeBase.hpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/node/NodeBase.cpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/node/NodeDispatcher.hpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/node/NodeDispatcher.cpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/node/models/InboundNodeModel.hpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/node/models/InboundNodeModel.cpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/node/models/OutboundNodeModel.hpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/node/models/OutboundNodeModel.cpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/node/models/RuleNodeModel.hpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/node/models/RuleNodeModel.cpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/node/models/ChainOutboundNodeModel.cpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/node/models/ChainOutboundNodeModel.hpp
    # NodeEditor Widgets
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/node/widgets/RuleWidget.cpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/node/widgets/RuleWidget.hpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/node/widgets/RuleWidget.ui
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/node/widgets/InboundOutboundWidget.cpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/node/widgets/InboundOutboundWidget.hpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/node/widgets/InboundOutboundWidget.ui
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/node/widgets/ChainWidget.cpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/node/widgets/ChainWidget.hpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/node/widgets/ChainWidget.ui
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/node/widgets/BalancerWidget.cpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/node/widgets/BalancerWidget.hpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/node/widgets/BalancerWidget.ui
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/node/widgets/ChainOutboundWidget.cpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/node/widgets/ChainOutboundWidget.hpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/node/widgets/ChainOutboundWidget.ui
    )

set(_QV2RAY_UI_SOURCES
    # Style Manager
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/Qv2rayWidgetApplication.cpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/Qv2rayWidgetApplication.hpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/common/WidgetUIBase.hpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/common/QJsonModel.hpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/common/QJsonModel.cpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/styles/StyleManager.cpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/styles/StyleManager.cpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/styles/StyleManager.hpp
    # Models
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/models/ConnectionModelHelper.cpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/models/ConnectionModelHelper.hpp
    # UI Widgets
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/widgets/ConnectionInfoWidget.hpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/widgets/ConnectionInfoWidget.cpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/widgets/QvAutoCompleteTextEdit.hpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/widgets/QvAutoCompleteTextEdit.cpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/widgets/RouteSettingsMatrix.hpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/widgets/RouteSettingsMatrix.cpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/widgets/ConnectionSettingsWidget.hpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/widgets/ConnectionSettingsWidget.cpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/widgets/ConnectionItemWidget.hpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/widgets/ConnectionItemWidget.cpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/widgets/StreamSettingsWidget.hpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/widgets/StreamSettingsWidget.cpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/widgets/InboundSettingsWidget.cpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/widgets/InboundSettingsWidget.hpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/widgets/DnsSettingsWidget.cpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/widgets/DnsSettingsWidget.hpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/widgets/CertificateItemWidget.ui
    # Complex Widgets
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/widgets/complex/ChainEditorWidget.cpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/widgets/complex/ChainEditorWidget.hpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/widgets/complex/RoutingEditorWidget.cpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/widgets/complex/RoutingEditorWidget.hpp
    # Editors
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/editors/w_InboundEditor.cpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/editors/w_InboundEditor.hpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/editors/w_JsonEditor.cpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/editors/w_JsonEditor.hpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/editors/w_OutboundEditor.cpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/editors/w_OutboundEditor.hpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/editors/w_RoutesEditor.hpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/editors/w_RoutesEditor.cpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/editors/w_ChainSha256Editor.hpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/editors/w_ChainSha256Editor.cpp
    # Windows
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/windows/w_ImportConfig.hpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/windows/w_ImportConfig.cpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/windows/w_MainWindow.hpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/windows/w_MainWindow.cpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/windows/w_MainWindow_extra.cpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/windows/w_PreferencesWindow.hpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/windows/w_PreferencesWindow.cpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/windows/w_PluginManager.hpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/windows/w_PluginManager.cpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/windows/w_ScreenShot_Core.hpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/windows/w_ScreenShot_Core.cpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/windows/w_GroupManager.hpp
    ${QVMESSOCKET_QWIDGETS_UI_BASEDIR}/windows/w_GroupManager.cpp
    )

set(QVMESSOCKET_UI_WIDGET_SOURCES ${_QVMESSOCKET_UI_FORMS} ${_QVMESSOCKET_UI_SOURCES} ${_QVMESSOCKET_UI_NODEEDITOR_SOURCES})
