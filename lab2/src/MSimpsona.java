import java.util.ArrayList;

public class MSimpsona {

    private double a;
    private double b;
    private double n;

    public MSimpsona(double a, double b, double n){
        this.a = a;
        this.b = b;
        this.n = n;
    }

    public static double f(double x){
        return (Math.sin(0.4*x*x-2.1))/( Math.sqrt(1.1*x+0.3) );
    }

    public double oblicz(){

        double sum = f(a)+f(b);
        double h=0.0;
        ArrayList<Double> array = new ArrayList<Double>();

        array.add(a);
        //xi
        for(int i = 1; i <= n-1;i++){
            array.add(a+(i/n)*(b-a));
            sum+=2*f(a+(i/n)*(b-a));
        }
        array.add(b);

        //ti
        for(int i = 0; i <= n-1;i++){
            sum+=4*f( (array.get(i+1) + array.get(i))/2 );
            h=(array.get(i+1)-array.get(i))/2;
        }

        return sum*(h/3);
    }
}
