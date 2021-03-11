public class M_Trapezow extends Thread{

    final private double ai;
    final private double bi;
    final private double ni;
    double wynik;


    public M_Trapezow(double ai, double bi, double ni){
        this.ai=ai;
        this.bi=bi;
        this.ni=ni;
    }

    public void run(){
        wynik = new MTrapezow(ai,bi,ni).oblicz();
    }
}