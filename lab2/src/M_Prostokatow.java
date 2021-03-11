public class M_Prostokatow extends Thread{

    final private double ai;
    final private double bi;
    final private int ni;
    double wynik;

    public M_Prostokatow(double ai, double bi, int ni){
        this.ai=ai;
        this.bi=bi;
        this.ni=ni;
    }

    public void run(){
        wynik = new MProstokątów(ai,bi,ni).oblicz();
    }
}