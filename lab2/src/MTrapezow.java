public class MTrapezow {

    private double a;
    private double b;
    private double n;

    public MTrapezow(double a, double b, double n){
        this.a = a;
        this.b = b;
        this.n = n;
    }

    public static double f(double x){
        return (Math.sin(0.4*x*x-2.1))/( Math.sqrt(1.1*x+0.3) );
    }

    public double oblicz(){

        double h = ((b-a) /n);
        double sum = f(a)/2+f(b)/2;

        for(double i = 1; i <=n-1; i++){
            sum+=f(a+(i/n) * (b-a));
        }

        return h*sum;
    }
}
