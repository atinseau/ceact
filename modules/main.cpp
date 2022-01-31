#include <emscripten.h>
#include <iostream>
#include "tag.h"

using namespace std;

namespace Ceact
{
    class App
    {
        public:
            std::string render(Node &node)
            {
                return node.getInnerHTML();
            }
    };
}


string EMSCRIPTEN_KEEPALIVE render(void) {
    Ceact::App *app = new Ceact::App();
    Ceact::Div div = Ceact::Div({
        Ceact::Div({
            Ceact::Paragraph("Hello World!"),
        })
    }, {
        Ceact::Attribute("class", "container")
    });
    string render = app->render(div);
    return render;
}



