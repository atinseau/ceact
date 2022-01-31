//
// Created by Arthur Tinseau on 30/01/2022.
//

#ifndef MODULES_TAG_H
#define MODULES_TAG_H

#include "dom.h"

namespace Ceact
{
    class Div: public Node
    {
        public:
            Div(std::string innerText, Node::Attributes attributes = {}): Node("div", innerText, attributes) {}
            Div(Node::Children nth, Node::Attributes attributes = {}): Node("div", nth, attributes) {}
    };
    struct Paragraph: Node
    {
        public:
            Paragraph(std::string innerText): Node("p", innerText) {}
            Paragraph(Node::Children nth): Node("p", nth) {}
    };
    struct Heading: Node
    {
        public:
            Heading(std::string innerText): Node("h1", innerText) {}
            Heading(Node::Children nth): Node("h1", nth) {}
    };
};

#endif //MODULES_TAG_H
