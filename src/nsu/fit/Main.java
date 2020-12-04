package nsu.fit;

public class Main {
    public static void main(String[] args) {
        CpuInfo cpuInfo = CpuInfo.getInstance();
        System.out.println(cpuInfo.toString());
    }
}
