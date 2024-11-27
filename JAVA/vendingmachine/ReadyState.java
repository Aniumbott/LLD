package vendingmachine;

public class ReadyState implements VendingMachineState {
    private final VendingMachine vendingMachine;
    public ReadyState(VendingMachine vendingMachine) {
        this.vendingMachine = vendingMachine;
    }

    @Override
    public void selectProduct(Product product) {
        System.out.println("Product already selected: " + vendingMachine.getSelectedProduct().getName() + ". Please make a payment.");
    }

    @Override
    public void insertCoin(Coin coin) {
        vendingMachine.addCoin(coin);
        System.out.println("Coin inserted: " + coin.getValue());
        checkPaymentStatus();
    }

    @Override
    public void insertNote(Note note) {
        vendingMachine.addNote(note);
        System.out.println("Note inserted: " + note.getValue());
        checkPaymentStatus();
    }

    @Override
    public void dispenseProduct() {
        System.out.println("Please make a complete payment first.");
    }

    @Override
    public void returnChange() {
        System.out.println("Please make a payment first.");
    }

    private void checkPaymentStatus() {
        if(vendingMachine.getTotalPayment() >= vendingMachine.getSelectedProduct().getPrice()) {
            vendingMachine.setState(vendingMachine.getDispensingState());
        }
    }    
}
