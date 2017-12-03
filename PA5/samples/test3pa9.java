void main() {
    int a, b;
    a = readIntFromSTDIN();
    b = 0;
    for (int i = 0; i <= a; i++) {
        b += i;
    }
    printInt(b);
}