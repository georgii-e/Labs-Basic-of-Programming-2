import copy
def input_str(message):  #отримання тексту з консолі
    print(message)
    text=[]
    line=input()
    while line:
        text.append(line.strip(' ,.\n').split())
        line=input()
    return text

def write_text_to_file(path, text): #запис тексту у файл
    with open(path,'wt') as text_in_file:
        text_in_file.write(text)

def read_text_from_file(path): #зчитування тексту з файлу там перетворення рядків на список
    text=[]
    with open(path,'rt', encoding='utf-8') as text_from_file:
        while True:
            line=text_from_file.readline()
            if not line:
                break
            text.append(line.strip(',.\n ').split())
    return text

def N_times(text, n): #повертає новий список з словами, що повторюються більше n разів
    repeated_words=[] #список що зберігає слова, які повторюються
    new_text=copy.deepcopy(text) #копія з якої видалятимемо слова, що не повторюються
    for line in text:
        for word in line:
            if word not in repeated_words:
                num_of_repeats=0
                for line_c in text:
                   num_of_repeats+=line_c.count(word)
                if num_of_repeats>n:
                    repeated_words.append(word)
    for i in range(len(text)):
        for j in range(len(text[i])):
            if text[i][j] not in repeated_words:
                new_text[i].remove(text[i][j]) #видалення слів з копії списку
    return new_text   

def sort(text): #сортування списку за довжиною
    for line in text:
        for i in range(len(line)-1):
            for j in range(len(line)-i-1):
                if len(line[j])>len(line[j+1]):
                    line[j+1],line[j]=line[j],line[j+1]
    return text

def list_to_string(text): #перетворення списку у рядки, зі збереженням Enter'рів
    str_text=''
    for line in text:
        if line:
            str_text=str_text+" ".join(line)+"\n"
    return str_text

path1='oldFile.txt' #початковий файл
path2='newFile.txt' #кінцевий файл
text=input_str("Write your text in the console below \nLeave console line blank and press \"Enter\" to finish")
n=int(input("Write number of repetitions: "))
write_text_to_file(path1, list_to_string(text))
text=read_text_from_file(path1)
text=list_to_string(sort(N_times(text, n)))
#print(text)
write_text_to_file(path2,text) 


