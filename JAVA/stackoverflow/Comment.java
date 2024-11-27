package stackoverflow;

import java.util.Date;

public class Comment{
    private final int id;
    private final User author;
    private final String content;
    private final Date creationDate;

    public Comment(User user, String content) {
        this.author = user;
        this.content = content;
        this.creationDate = new Date();
        this.id = generateId();
    }

    private int generateId() {
        return (int) (System.currentTimeMillis() % Integer.MAX_VALUE);
    }
    
    public User getAuthor() {
        return author;
    }
    public String getContent() {
        return content;
    }
    public Date getCreationDate() {
        return creationDate;
    }
}
