package stackoverflow;

import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;
import java.util.List;

public class StackOverflow {
    private final Map<Integer, User> users;
    private final Map<Integer, Question> questions;
    private final Map<Integer, Answer> answers;
    private final Map<String, Tag> tags;

    public StackOverflow() {
        this.users = new ConcurrentHashMap<>();
        this.questions = new ConcurrentHashMap<>();
        this.answers = new ConcurrentHashMap<>();
        this.tags = new ConcurrentHashMap<>();
    }

    public User createUser(String username, String email) {
        User user = new User(users.size() + 1, username, email);
        users.put(user.getId(), user);
        return user;
    }

    public Question askQuestion(User author, String title, String content, List<String> tags) {
        Question question = author.askQuestion(title, content, tags);
        questions.put(question.getId(), question);
        for (Tag tag : question.getTags()) {
            this.tags.putIfAbsent(tag.getName(), tag);
        }
        return question;
    }

    public Answer ansQuestion(User author, Question question, String content) {
        Answer answer = author.ansQuestion(question, content);
        answers.put(answer.getId(), answer);
        return answer;
    }

    public Comment addComment(User author, Commentable commentable, String content) {
        Comment comment = author.addComment(commentable, content);
        return comment;
    }

    public void vote(User user, Votable votable, int value) {
        votable.vote(user, value);
    }

    public void acceptAnswer(Answer answer) {
        answer.markAccepted();
    }

    public List<Question> searchQuestions(String query) {
        return questions.values().stream()
                .filter(
                    q -> q.getTitle().toLowerCase().contains(query.toLowerCase()) || 
                    q.getContent().toLowerCase().contains(query.toLowerCase()) || 
                    q.getTags().stream().anyMatch(t -> t.getName().equalsIgnoreCase(query)))
                .toList();
    }

    public List<Question> getQuestionsByAuthor(User author) {
        return author.getQuestions();
    }
    
    public static void main(String[] args) {
        System.out.println("Hello, World!");
    }
}