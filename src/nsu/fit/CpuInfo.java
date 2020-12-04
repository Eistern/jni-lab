package nsu.fit;

public class CpuInfo {
    static {
        System.loadLibrary("cpp");
    }

    public static native CpuInfo getInstance();

    private int coreNumber;
    private String model;

    private CpuInfo(int coreNumber, String model) {
        this.coreNumber = coreNumber;
        this.model = model;
    }

    @Override
    public String toString() {
        return "CpuInfo{" +
                "coreNumber=" + coreNumber +
                ", model='" + model + '\'' +
                '}';
    }
}
