#include "GUI/Application.h"
#include "GUI/AsokaConsole.h"
#include "Core/Property.h"
#include "Core/Core.h"
#include "Asoka.h"

#include "Core/Tests/PropertyTest.h"


int main(int argc, char *argv[])
{
    Application app(argc, argv);

    AsokaConsole *console = new AsokaConsole(); 
    console->show();

    PropertyTest test;

    asoka::tester->run();

    return app.exec();
}
