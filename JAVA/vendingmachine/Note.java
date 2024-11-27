package vendingmachine;

public enum Note {
    TEN_N(10), TWENTY_N(20), FIFTY_N(50), HUNDRED_N(100), TWO_HUNDRED_N(200);
    private final int value;

    Note(int value) {
        this.value = value;
    }

    public int getValue() {
        return value;
    }
}
