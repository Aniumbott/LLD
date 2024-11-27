package vendingmachine;

public class VendingMachine{
    private static VendingMachine instance;
    private Product selectedProduct;
    private int totalPayment;
    Inventory inventory;
    
    private final VendingMachineState idleState;
    private final VendingMachineState readyState;
    private final VendingMachineState dispensingState;
    private final VendingMachineState returnChangeState;
    private VendingMachineState currentState;

    private VendingMachine(){
        inventory = new Inventory();
        idleState = new IdleState(this);
        readyState = new ReadyState(this);
        dispensingState = new DispensingState(this);
        returnChangeState = new ReturnChangeState(this);
        currentState = idleState;
        selectedProduct = null;
        totalPayment = 0;
    }

    public static synchronized VendingMachine getInstance() {
        if(instance == null) {
            instance = new VendingMachine();
        }
        return instance;
    }

    public void selectProduct(Product product) {
        currentState.selectProduct(product);
    }

    public void insertCoin(Coin coin) {
        currentState.insertCoin(coin);
    }

    public void insertNote(Note note) {
        currentState.insertNote(note);
    }

    public void dispenseProduct(){
        currentState.dispenseProduct();
    }

    public void returnChange(){
        currentState.returnChange();
    }

    void setState(VendingMachineState state) {
        currentState = state;
    }

    VendingMachineState getIdleState() {
        return idleState;
    }

    VendingMachineState getReadyState() {
        return readyState;
    }

    VendingMachineState getDispensingState() {
        return dispensingState;
    }

    VendingMachineState getReturnChangeState() {
        return returnChangeState;
    }

    Product getSelectedProduct() {
        return selectedProduct;
    }

    int getTotalPayment() {
        return totalPayment;
    }

    void setSelectedProduct(Product product) {
        selectedProduct = product;
    }

    void resetSelectedProduct() {
        selectedProduct = null;
    }

    void addCoin(Coin coin){
        totalPayment += coin.getValue();
    }

    void addNote(Note note){
        totalPayment += note.getValue();
    }

    void resetPayment(){
        totalPayment = 0;
    }
}