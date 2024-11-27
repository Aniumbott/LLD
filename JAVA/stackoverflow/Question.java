package stackoverflow;

import java.util.List;
import java.util.ArrayList;
import java.util.Date;

public class Question implements Votable, Commentable {
    private final int id;
    private final String title;
    private final String content;
    private final User author;
    private final Date creationDate;
    private final List<Answer> answers;
    private final List<Comment> comments;
    private final List<Tag> tags;
    private final List<Vote> votes;  
    
    public Question(User author, String title, String content, List<String> tags) {
        this.id = generateId();
        this.creationDate = new Date();
        this.author = author;
        this.title = title;
        this.content = content;
        this.comments = new ArrayList<>();
        this.answers = new ArrayList<>();
        this.votes = new ArrayList<>();
        this.tags = new ArrayList<>();
        for(String tag : tags) {
            this.tags.add(new Tag(tag));
        }
    }

    @Override
    public void vote(User user, int value) {
        if(value != 1 && value != -1) {
           throw new IllegalArgumentException("Vote value can only be 1 or -1");
        }
        votes.removeIf(v -> v.getUser().equals(user));
        votes.add(new Vote(user, value));
        author.updateReputation(value * 5);
    }

    @Override
    public int getVoteCount() {
        return votes.stream().mapToInt(Vote::getValue).sum();
    }

    @Override
    public void addComment(Comment comment) {
        comments.add(comment);
    }

    @Override
    public List<Comment> getComments() {
        return new ArrayList<>(comments);
    }

    public void addAnswer(Answer answer) {
        if(!answers.contains(answer)) {
            answers.add(answer);
        }
    }

    private int generateId() {
        return (int) (System.currentTimeMillis() % Integer.MAX_VALUE);
    }

    public int getId() { return id; }
    public User getAuthor() { return author; }
    public String getTitle() { return title; }
    public String getContent() { return content; }
    public Date getCreationDate() { return creationDate; }
    public List<Answer> getAnswers() { return answers; }
    public List<Tag> getTags() { return tags; }
}
