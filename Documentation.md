#DOCUMENTATION

A **BoundingBox** is a box which contains **UIElement**s. Create one like so:\
`BoundingBox myBox(x, y, width, height, margin, columns, rows);`\
x, y -- position (integer)\
width, height -- size (integer)\
margin -- distance between edge of box and elements, as well as between elements in the box (integer)\
columns, rows -- how many rows and columns of elements you want the box to contain. Only necessary when using "right" or "bottom" positioning for elements. (integer)

BoundingBoxes also contain an sf::RectangleShape called **rect** (accessed as **myBox.rect**) which can be used to visualize box.

A **UIElement** is what you build your UI out of. Create one like so:\
`UIElement myElement(width, height, box);`\
width, height -- size of the element (integer)\
box -- pointer to a BoundingBox, which will contain the element (BoundingBox*)

Check whether mouse is above element:\
`if(myElement.mouseIn(x, y))...`\
x, y -- mouse position (int)

Position an element:\
`myElement.position(horizontal, vertical);`\
horizontal -- where in the box to place the element, either "left", "center" or "right" (std::string)\
vertical -- where in the box to place the element, either "top", "center" or "bottom" (std::string)

An **Image** is a type of UIElement which has an image which can be rendered. They are created using the UIElement default contructor.

Initialize them:\
`myImage.initialize(path, scaleX, scaleY);`\
path -- path to image file (std::string)\
scaleX, scaleY -- x and y scale for the image (int)

Render them:\
`myImage.render(window);`\
window -- window to draw it to (sf::RenderWindow)
