tweet = "This is an example tweet @username #hashtag RT mention CC comment"
words = tweet.split()
filtered_words = [word for word in words if not (word.startswith('@') or word.startswith('#') or word == 'RT' or word == 'CC')]
result = " ".join(filtered_words)
print(result)
