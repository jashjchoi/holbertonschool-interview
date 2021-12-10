#!/usr/bin/python3
"""Count it
"""
import requests
import sys


def count_words(subreddit, word_list, after=None, count={}):
    """parses the title of all hot articles
    and prints a sorted count of given keywords
    """
    if word_list == []:
        return None
    else:
        lower_list = (map(lambda word: word.lower(), word_list))
        word_list = list(lower_list)
    if after is None:
        req = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
    else:
        req = 'https://www.reddit.com/r/{}/hot.json?after={}'.format(
            subreddit, after)
    hot_request = requests.get(req,
                               headers={"user-agent": "user"},
                               allow_redirects=False)
    try:
        data = hot_request.json().get("data")
    except:
        return
    for word in word_list:
        if word not in count.keys():
            count[word] = 0
    children = data.get("children")
    for child in children:
        title = (child.get("data").get("title").lower())
        title = title.split(' ')
        for word in word_list:
            count[word] += title.count(word)
    after = data.get("after")
    if after is not None:
        return count_words(subreddit, word_list, after, count)
    else:
        sorted_subs = sorted(count.items(), key=lambda x: (-x[1], x[0]))
        for i in sorted_subs:
            if i[1] != 0:
                print(i[0] + ": " + str(i[1]))
