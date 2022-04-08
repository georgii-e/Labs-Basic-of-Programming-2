def input_str(message):  #отримання тексту з консолі
    print(message)
    text=""
    line=input()
    while line!="\x18":
        text = text+ line+"\n" 
        line=input()
    return text

def write_text_to_file(path, text): #запис тексту у файл
    with open(path,'wt') as text_in_file:
        text_in_file.write(text)

def read_text_from_file(path): #зчитування тексту з файлу та перетворення рядків на список
    text=[]
    print("\nYou input:")
    with open(path,'rt', encoding='utf-8') as text_from_file:
        while True:
            line=text_from_file.readline()
            print(line, end= '')
            if not line:
                break
            text.append(line.replace(',', ' ').replace('.', ' ').strip('\n ').split())
    return text

def N_times(text, n): #повертає список з словами, що повторюються більше n разів
    repeated_words=[] #список що зберігає слова, які повторюються
    not_repeated_words=[] #список що зберігає слова, які не повторюються
    for line in text:
        for word in line:
            if word.lower() not in repeated_words and word.lower() not in not_repeated_words:
                num_of_repeats=0
                for line_cur in text:
                    for word_cur in line_cur:
                        if word_cur.lower()==word.lower():
                            num_of_repeats+=1                  
                if num_of_repeats>n:
                    repeated_words.append(word.lower())
                else:
                    not_repeated_words.append(word.lower())
    return repeated_words   

def sort(text): #сортування списку за довжиною
        for i in range(len(text)-1):
            for j in range(len(text)-i-1):
                if len(text[j])>len(text[j+1]):
                    text[j+1],text[j]=text[j],text[j+1]
        return " ".join(text)

path1='oldFile.txt' #початковий файл
path2='newFile.txt' #кінцевий файл
text=input_str("Write your text in the console below \nPress Ctrl+x and then \"Enter\" to finish")
n=int(input("Write number of repetitions: "))
write_text_to_file(path1, text)
text=read_text_from_file(path1)
text=(sort(N_times(text, n)))
print("\nSorted words\n", text)
write_text_to_file(path2,text) 


