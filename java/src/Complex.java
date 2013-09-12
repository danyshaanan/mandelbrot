public class Complex {

    private double real;
    private double imaginary;

    public Complex(double real, double imaginary){
        this.real = real;
        this.imaginary = imaginary;
    }

    public Complex(){
        this.real = 0;
        this.imaginary = 0;
    }

    public double getReal(){
        return real;
    }

    public double getImaginary(){
        return imaginary;
    }

    public Complex add(Complex rightTerm){
        double real = this.real + rightTerm.getReal();
        double imaginary = this.imaginary + rightTerm.getImaginary();

        return new Complex(real, imaginary);
    }

    public Complex subtract(Complex rightTerm){
        double real = this.real - rightTerm.getReal();
        double imaginary = this.imaginary - rightTerm.getImaginary();

        return new Complex(real, imaginary);
    }

    public Complex multiply(Complex rightTerm){
        double zr = this.real;              double zi = this.imaginary;
        double wr = rightTerm.getReal();    double wi = rightTerm.getImaginary();

        double real = zr * wr - zi * wi;
        double imaginary = zi * wr + zr * wi;

        return new Complex(real, imaginary);
    }

    public String toString(){
        return real + " + " + imaginary + "i";
    }
}
