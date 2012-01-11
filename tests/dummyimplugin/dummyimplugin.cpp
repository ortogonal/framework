#include "dummyimplugin.h"
#include "dummyinputmethod.h"

#include <QtPlugin>


DummyImPlugin::DummyImPlugin()
{
    allowedStates << Maliit::OnScreen << Maliit::Hardware << Maliit::Accessory;
}

QString DummyImPlugin::name() const
{
    return "DummyImPlugin";
}

MAbstractInputMethod *
DummyImPlugin::createInputMethod(MAbstractInputMethodHost *host,
                                 QWidget *mainWindow)
{
    return new DummyInputMethod(host, mainWindow);
}

QSet<Maliit::HandlerState> DummyImPlugin::supportedStates() const
{
    return allowedStates;
}

Q_EXPORT_PLUGIN2(dummyimplugin, DummyImPlugin)

