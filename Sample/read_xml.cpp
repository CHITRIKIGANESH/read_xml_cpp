#include <iostream>
#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"

int main() {
    try {
        // Load XML file
        rapidxml::file<> xmlFile("example.xml");
        rapidxml::xml_document<> doc;
        doc.parse<0>(xmlFile.data());

        // Access root node
        rapidxml::xml_node<>* rootNode = doc.first_node("note");

        // Check if root node exists
        if (rootNode) {
            // Iterate over child nodes
            for (rapidxml::xml_node<>* node = rootNode->first_node(); node; node = node->next_sibling()) {
                // Retrieve data from child nodes
                std::cout << "Node name: " << node->name() << std::endl;
                std::cout << "Node value: " << node->value() << std::endl;
            }
        } else {
            std::cerr << "Error: Root node 'root' not found in XML file." << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
