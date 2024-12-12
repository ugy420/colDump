function print(){
    var l = parseInt(prompt("Enter length"));
    var w = parseInt(prompt("Enter width"));
    document.write("Area: " + l*w + "<br>" + " Perimeter: " + (l+w)*2);
}
print();