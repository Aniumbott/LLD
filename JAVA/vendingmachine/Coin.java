package vendingmachine;

public enum Coin {
    ONE_C(1), TWO_C(2), FIVE_C(5), TEN_C(10), TWENTY_C(20);

    private final int value;

    Coin(int value) {
        this.value = value;
    }

    public int getValue() {
        return value;
    }
}
