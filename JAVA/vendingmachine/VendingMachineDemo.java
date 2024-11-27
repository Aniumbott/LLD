package vendingmachine;

public class VendingMachineDemo {
    public static void run(){
        VendingMachine vendingMachine = VendingMachine.getInstance();

        // Products
        Product Sprite = new Product("Sprite", 40);
        Product Maza = new Product("Maza", 45);
        Product Slice = new Product("Slice", 50);
        Product Fenta = new Product("Fenta", 35);
        Product Limca = new Product("Limca", 42);
        Product Coke = new Product("Coke", 48);
        Product Sosyo = new Product("Sosyo", 30);
        Product Sevenup = new Product("Sevenup", 40);
        Product Thumbsup = new Product("Thumbsup", 35);
        Product Soda = new Product("Soda", 25);
        
        // Add products
        vendingMachine.inventory.addProduct(Sprite, 10);            
        vendingMachine.inventory.addProduct(Maza, 10);        
        vendingMachine.inventory.addProduct(Slice, 10);        
        vendingMachine.inventory.addProduct(Fenta, 10);        
        vendingMachine.inventory.addProduct(Limca, 10);        
        vendingMachine.inventory.addProduct(Coke, 10);        
        vendingMachine.inventory.addProduct(Sosyo, 10);        
        vendingMachine.inventory.addProduct(Sevenup, 10);            
        vendingMachine.inventory.addProduct(Thumbsup, 10);        
        vendingMachine.inventory.addProduct(Soda, 10); 
        
        // Select Product
        vendingMachine.selectProduct(Coke);
        
        // Make payment
        vendingMachine.insertNote(Note.FIFTY_N);

        // Dispense Product
        vendingMachine.dispenseProduct();

        // Return change
        vendingMachine.returnChange();

        // Select Product
        vendingMachine.selectProduct(Coke);

        // Make payment
        vendingMachine.insertNote(Note.TWENTY_N);
        vendingMachine.insertNote(Note.TWENTY_N);
        
        // Dispense product
        vendingMachine.dispenseProduct();

        // Make remaining payment
        vendingMachine.insertCoin(Coin.FIVE_C);
        vendingMachine.insertCoin(Coin.TWO_C);
        vendingMachine.insertCoin(Coin.ONE_C);

        // Dispense product
        vendingMachine.dispenseProduct();

        // Return Change
        vendingMachine.returnChange();
    }
}
