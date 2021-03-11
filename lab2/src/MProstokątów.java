import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class MProstokątów {

    private double a;
    private double b;
    private int n;

    public MProstokątów(double a, double b, int n){
        this.a = a;
        this.b = b;
        this.n = n;
    }

    public static double f(double x){
        return (Math.sin(0.4*x*x-2.1))/( Math.sqrt(1.1*x+0.3) );
    }

    public double oblicz(){

        double wynik = (b-a)/2;

        double sum = 0.0;

        BufferedReader reader;
        try{
            reader = new BufferedReader((new FileReader(n+".txt")));
            String line = reader.readLine();
            while(line != null){

                String[] parts = line.split(" ");
                sum+=Double.parseDouble(parts[1]) * f( (b-a)/2 * Double.parseDouble(parts[0]) + (b+a)/2 );

                line = reader.readLine();
            }
        }catch (IOException e){
            e.printStackTrace();
        }

        wynik*=sum;



        return wynik;
    }
}
