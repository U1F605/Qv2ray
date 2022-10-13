set(QCLASH_QWIDGETS_UI_BASEDIR ${CMAKE_SOURCE_DIR}/src/ui/widgets)
add_definitions(-DQAPPLICATION_CLASS=QApplication)

set(_QCLASH_UI_FORMS
    ${QCLASH_QWIDGETS_UI_BASEDIR}/editors/w_OutboundEditor.ui
    ${QCLASH_QWIDGETS_UI_BASEDIR}/editors/w_InboundEditor.ui
    ${QCLASH_QWIDGETS_UI_BASEDIR}/editors/w_JsonEditor.ui
    ${QCLASH_QWIDGETS_UI_BASEDIR}/editors/w_RoutesEditor.ui
    ${QCLASH_QWIDGETS_UI_BASEDIR}/editors/w_ChainSha256Editor.ui
    #
    ${QCLASH_QWIDGETS_UI_BASEDIR}/widgets/StreamSettingsWidget.ui
    ${QCLASH_QWIDGETS_UI_BASEDIR}/widgets/ConnectionInfoWidget.ui
    ${QCLASH_QWIDGETS_UI_BASEDIR}/widgets/ConnectionItemWidget.ui
    ${QCLASH_QWIDGETS_UI_BASEDIR}/widgets/RouteSettingsMatrix.ui
    ${QCLASH_QWIDGETS_UI_BASEDIR}/widgets/InboundSettingsWidget.ui
    ${QCLASH_QWIDGETS_UI_BASEDIR}/widgets/ConnectionSettingsWidget.ui
    #
    ${QCLASH_QWIDGETS_UI_BASEDIR}/windows/w_GroupManager.ui
    ${QCLASH_QWIDGETS_UI_BASEDIR}/windows/w_ImportConfig.ui
    ${QCLASH_QWIDGETS_UI_BASEDIR}/windows/w_MainWindow.ui
    ${QCLASH_QWIDGETS_UI_BASEDIR}/windows/w_PreferencesWindow.ui
    ${QCLASH_QWIDGETS_UI_BASEDIR}/windows/w_PluginManager.ui
    ${QCLASH_QWIDGETS_UI_BASEDIR}/windows/w_ScreenShot_Core.ui
    #
    ${QCLASH_QWIDGETS_UI_BASEDIR}/widgets/complex/ChainEditorWidget.ui
    ${QCLASH_QWIDGETS_UI_BASEDIR}/widgets/complex/RoutingEditorWidget.ui
    )

set(_QCLASH_UI_NODEEDITOR_SOURCES
    # NodeEditor Models
    ${QCLASH_QWIDGETS_UI_BASEDIR}/node/NodeBase.hpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/node/NodeBase.cpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/node/NodeDispatcher.hpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/node/NodeDispatcher.cpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/node/models/InboundNodeModel.hpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/node/models/InboundNodeModel.cpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/node/models/OutboundNodeModel.hpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/node/models/OutboundNodeModel.cpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/node/models/RuleNodeModel.hpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/node/models/RuleNodeModel.cpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/node/models/ChainOutboundNodeModel.cpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/node/models/ChainOutboundNodeModel.hpp
    # NodeEditor Widgets
    ${QCLASH_QWIDGETS_UI_BASEDIR}/node/widgets/RuleWidget.cpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/node/widgets/RuleWidget.hpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/node/widgets/RuleWidget.ui
    ${QCLASH_QWIDGETS_UI_BASEDIR}/node/widgets/InboundOutboundWidget.cpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/node/widgets/InboundOutboundWidget.hpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/node/widgets/InboundOutboundWidget.ui
    ${QCLASH_QWIDGETS_UI_BASEDIR}/node/widgets/ChainWidget.cpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/node/widgets/ChainWidget.hpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/node/widgets/ChainWidget.ui
    ${QCLASH_QWIDGETS_UI_BASEDIR}/node/widgets/BalancerWidget.cpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/node/widgets/BalancerWidget.hpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/node/widgets/BalancerWidget.ui
    ${QCLASH_QWIDGETS_UI_BASEDIR}/node/widgets/ChainOutboundWidget.cpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/node/widgets/ChainOutboundWidget.hpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/node/widgets/ChainOutboundWidget.ui
    )

set(_QCLASH_UI_SOURCES
    # Style Manager
    ${QCLASH_QWIDGETS_UI_BASEDIR}/QvWidgetApplication.cpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/QvWidgetApplication.hpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/common/WidgetUIBase.hpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/common/QJsonModel.hpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/common/QJsonModel.cpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/styles/StyleManager.cpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/styles/StyleManager.cpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/styles/StyleManager.hpp
    # Models
    ${QCLASH_QWIDGETS_UI_BASEDIR}/models/ConnectionModelHelper.cpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/models/ConnectionModelHelper.hpp
    # UI Widgets
    ${QCLASH_QWIDGETS_UI_BASEDIR}/widgets/ConnectionInfoWidget.hpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/widgets/ConnectionInfoWidget.cpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/widgets/QvAutoCompleteTextEdit.hpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/widgets/QvAutoCompleteTextEdit.cpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/widgets/RouteSettingsMatrix.hpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/widgets/RouteSettingsMatrix.cpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/widgets/ConnectionSettingsWidget.hpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/widgets/ConnectionSettingsWidget.cpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/widgets/ConnectionItemWidget.hpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/widgets/ConnectionItemWidget.cpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/widgets/StreamSettingsWidget.hpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/widgets/StreamSettingsWidget.cpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/widgets/InboundSettingsWidget.cpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/widgets/InboundSettingsWidget.hpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/widgets/CertificateItemWidget.ui
    # Complex Widgets
    ${QCLASH_QWIDGETS_UI_BASEDIR}/widgets/complex/ChainEditorWidget.cpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/widgets/complex/ChainEditorWidget.hpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/widgets/complex/RoutingEditorWidget.cpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/widgets/complex/RoutingEditorWidget.hpp
    # Editors
    ${QCLASH_QWIDGETS_UI_BASEDIR}/editors/w_InboundEditor.cpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/editors/w_InboundEditor.hpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/editors/w_JsonEditor.cpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/editors/w_JsonEditor.hpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/editors/w_OutboundEditor.cpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/editors/w_OutboundEditor.hpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/editors/w_RoutesEditor.hpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/editors/w_RoutesEditor.cpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/editors/w_ChainSha256Editor.hpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/editors/w_ChainSha256Editor.cpp
    # Windows
    ${QCLASH_QWIDGETS_UI_BASEDIR}/windows/w_ImportConfig.hpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/windows/w_ImportConfig.cpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/windows/w_MainWindow.hpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/windows/w_MainWindow.cpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/windows/w_MainWindow_extra.cpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/windows/w_PreferencesWindow.hpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/windows/w_PreferencesWindow.cpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/windows/w_PluginManager.hpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/windows/w_PluginManager.cpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/windows/w_ScreenShot_Core.hpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/windows/w_ScreenShot_Core.cpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/windows/w_GroupManager.hpp
    ${QCLASH_QWIDGETS_UI_BASEDIR}/windows/w_GroupManager.cpp
    )

set(QCLASH_UI_WIDGET_SOURCES ${_QCLASH_UI_FORMS} ${_QCLASH_UI_SOURCES} ${_QCLASH_UI_NODEEDITOR_SOURCES})
