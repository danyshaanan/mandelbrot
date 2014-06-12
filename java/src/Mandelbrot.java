import javax.swing.*;
import java.awt.*;
import java.awt.image.BufferedImage;

public class Mandelbrot {

    private static final int INITIAL_WIDTH = 750;
    private static final int INITIAL_HEIGHT = 500;

    private JFrame frame;
    private BufferedImage image;

    private static Mandelbrot mandelbrot;

    public static void main(String [] args){
        mandelbrot = new Mandelbrot();
    }

    public Mandelbrot(){
        createFrame();
    }

    private void createFrame(){
        JFrame frame = this.frame = new JFrame("Mandelbrot");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        BufferedImage image = this.image = new BufferedImage(INITIAL_WIDTH, INITIAL_HEIGHT, BufferedImage.TYPE_INT_RGB);
        ImagePanel panel = new ImagePanel(image);

        frame.add(panel, BorderLayout.CENTER);

        panel.getSize().getWidth();
        frame.setSize(INITIAL_WIDTH, INITIAL_HEIGHT);
        frame.setVisible(true);
    }

}
