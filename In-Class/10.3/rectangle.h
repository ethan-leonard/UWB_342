
typedef struct {
    int width;
    int height;
} Rectangle;

int findArea(Rectangle r) {
    int areaR = r.width * r.height;
    return areaR;
}