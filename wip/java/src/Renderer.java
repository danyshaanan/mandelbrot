import java.awt.*;
import java.awt.image.BufferedImage;

public class Renderer {

    private static final int DEFAULT_MAX_ITERATION = 100;
    private static final int DEFAULT_ZOOM = 1;
    private static final Complex DEFAULT_CENTER = new Complex(-1.75,0);

    private BufferedImage image;
    private int maxIteration;
    private int zoom;
    private Complex center;

    public Renderer(BufferedImage image, int maxIterations, int zoom, Complex center){
        this.image = image;
        this.maxIteration = maxIterations;
        this.zoom = zoom;
        this.center = center;
    }

    public Renderer(BufferedImage image){
        this.image = image;
        this.maxIteration = DEFAULT_MAX_ITERATION;
        this.zoom = DEFAULT_ZOOM;
        this.center = DEFAULT_CENTER;
    }

    private int escapeTime(double Cx, double Cy){
        int time;

        for(time = 0; time < maxIteration; time++){

        }

        return time;
    }
}
