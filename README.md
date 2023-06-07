# QUI
Quick UI--UI framework for SFML
version 1.0 (incomplete)

Can be used to create desktop app UIs using a simple system similar to the HTML/CSS div system.

##USAGE:
The system for creating a UI with QUI is simple:
-Create bounding boxes
-Add elements to them

A **BoundingBox** is a box which contains **UIElement**s. Create one like so:
`BoundingBox myBox(x, y, width, height, margin, columns, rows);`
x, y -- position (integer)
width, height -- size (integer)
margin -- distance between edge of box and elements, as well as between elements in the box (integer)
columns, rows -- how many rows and columns of elements you want the box to contain. Only necessary when using "right" or "bottom" positioning for elements. (integer)

BoundingBoxes also contain an sf::RectangleShape called **rect** (accessed as **myBox.rect**) which can be used to visualize box.

A **UIElement** is what you build your UI out of. Eventually, I will add custom preset ones like buttons or drop-diown menus. Create one like so:
`UIElement myElement(path to image file, width, height, box);`
path to image file -- the path to the image to be displayed when this element is rendered (std::string)
width, height -- size of the element (integer)
box -- pointer to a BoundingBox, which will contain the element (BoundingBox*)

Render an element:
`myElement.render(myWindow);`
myWindow -- window to draw it to (sf::RenderWindow)

Position an element:
`myElement.position(horizontal, vertical);`
horizontal -- where in the box to place the element, either "left" or "right" (std::string)
vertical -- where in the box to place the element, either "top" or "bottom" (std::string)
