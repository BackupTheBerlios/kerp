/*
 * Copyright (C) 2003 Arash Bijanzadeh <a.bijanzadeh@linuxiran.org>
 */

#include "kerp.h"
#include <kapplication.h>
#include <dcopclient.h>
#include <kaboutdata.h>
#include <kcmdlineargs.h>
#include <klocale.h>

#include <qstring.h>

#include <stdio.h>

static const char *description =
    I18N_NOOP("A KDE ERP Application");

static const char *version = "0.01";

static KCmdLineOptions options[] =
{
    { "+[URL]", I18N_NOOP( "Document to open." ), 0 },
    { 0, 0, 0 }
};

int main(int argc, char **argv)
{
    KAboutData about("kerp", I18N_NOOP("kerp"), version, description,
                     KAboutData::License_GPL, "(C) 2003 Arash Bijanzadeh", 0, 0, "a.bijanzadeh@linuxiran.org");
    about.addAuthor( "Arash Bijanzadeh", 0, "a.bijanzadeh@linuxiran.org" );
    KCmdLineArgs::init(argc, argv, &about);
    KCmdLineArgs::addCmdLineOptions(options);
    KApplication app;

    // register ourselves as a dcop client
    app.dcopClient()->registerAs(app.name(), false);

    // see if we are starting with session management
    if (app.isRestored())
    {
        RESTORE(kerp);
    }
    else
    {
        // no session.. just start up normally
        KCmdLineArgs *args = KCmdLineArgs::parsedArgs();
        if (args->count() == 0)
        {
            kerp *widget = new kerp;
            widget->show();
        }
        else
        {
            int i = 0;
            for (; i < args->count(); i++)
            {
                kerp *widget = new kerp;
                widget->show();
                widget->load(args->url(i));
            }
        }
        args->clear();
    }

    return app.exec();
}
