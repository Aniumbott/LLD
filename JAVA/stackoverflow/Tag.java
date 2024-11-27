package stackoverflow;

public class Tag {
    private int id;
    private final String name;

    public Tag(String name) {
        this.name = name;
        this.id = generateId();
    }

    private int generateId() {
        return (int) (System.currentTimeMillis() % Integer.MAX_VALUE);
    }

    public String getName() {
        return name;
    }

    public int getId() {
        return id;
    }

}
