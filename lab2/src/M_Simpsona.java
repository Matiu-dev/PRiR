public class M_Simpsona extends Thread{

    final private double ai;
    final private double bi;
    final private double ni;
    double wynik;

    public M_Simpsona(double ai, double bi, double ni){
        this.ai=ai;
        this.bi=bi;
        this.ni=ni;
    }

    public void run(){
        wynik = new MSimpsona(ai, bi, ni).oblicz();
    }
}