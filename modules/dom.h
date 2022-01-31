//
// Created by Arthur Tinseau on 30/01/2022.
//
#ifndef MODULES_NODE_H
#define MODULES_NODE_H

#include <initializer_list>
#include <utility>

namespace Ceact
{
    class Attribute
    {
        public:
            Attribute(const std::string& name, const std::string& value)
            {
                tuple = std::make_pair(name, value);
            }
            std::string getFormatted() const
            {
                return tuple.first + "=\"" + tuple.second + "\"";
            }
        private:
            std::pair<std::string, std::string> tuple;
    };


    class Node
    {
    public:
        typedef std::initializer_list<Node> Children;
        typedef std::initializer_list<Attribute> Attributes;

        Node(const std::string& tagName, const std::string& innerText = "", Attributes attributes = {}): tagName(tagName)
        {
            std::string innerHTML = "<" + tagName;
            if (attributes.size() > 0)
                innerHTML += " " + _getAttributes(attributes);
            innerHTML += ">" + innerText + "</" + tagName + ">";
            this->innerHTML = innerHTML;
        }
        Node(const std::string& tagName, Children nth, Attributes attributes = {}): tagName(tagName)
        {
            std::string innerHTML = "<" + tagName;
            if (attributes.size() > 0)
                innerHTML += " " + _getAttributes(attributes);
            innerHTML += ">";
            for (typename Children::iterator child = nth.begin(); child != nth.end(); child++)
            {
                innerHTML += child->getInnerHTML();
            }
            innerHTML += "</" + tagName + ">";
            this->innerHTML = innerHTML;
        }
        std::string getInnerHTML() const
        {
            return innerHTML;
        }
    private:
        std::string innerHTML;
        std::string tagName;

        std::string _getAttributes(Attributes attributes) const
        {
            std::string attributesString = "";
            int i = 0;
            for(typename Attributes::iterator attribute = attributes.begin(); attribute != attributes.end(); attribute++)
            {
                if (i < attributes.size() - 1)
                    attributesString += attribute->getFormatted() + " ";
                else
                    attributesString += attribute->getFormatted();
                i++;
            }
            return attributesString;
        }
    };
}

#endif //MODULES_NODE_H
