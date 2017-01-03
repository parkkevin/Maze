#ifndef MAZECOMPLEXITYPARTA_H
#define MAZECOMPLEXITYPARTA_H

/**
 * This class creates the grid with cells to be painted black.
 */
class MazeComplexityPartA
{
    private:
        enum PixelValues {BLACK, WHITE};
        const static int ROWS = 10;
        const static int COLS = 20;
    
        //This is the 2D array that stores the shape that will be painted.
        PixelValues canvas[ROWS][COLS];
    
        /**
         * This is the function that paints the canvas. It finds white cells and paints them black. When it 
         * comes to a black cell, it changes direction and looks for white cells. Once no more white cells 
         * are found, the function returns and program ends.
         */
        void fillBlack(PixelValues canvas[][COLS], int i, int j);
        
    public:
    
        /**
         * This is the default constructor.
         */
        MazeComplexityPartA();
    
        /**
         * This function prints the canvas.
         */
        void print();
    
        /**
         * This is the function that gets called by main().
         */
        void fillBlack(int m, int n);
    
        /**
         * This function reads from input files and initializes canvas.
         */
        void readInput(PixelValues canvas[][COLS]);
};

#endif /* MAZECOMPLEXITYPARTA_H */
