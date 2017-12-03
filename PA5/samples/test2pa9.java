void main() {
    int a, b;
    a = readIntFromSTDIN();
    b = readIntFromSTDIN();
    if (a < b) {
        printInt(b);
    }
    if (b < a) {
        printInt(b);
    }
}