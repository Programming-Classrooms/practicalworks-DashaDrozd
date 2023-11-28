# Практические работы по C++


### Коллабораторы репозитория

<a id=repo_collaborators pos=begin></a>
|     №     |                   GitHub-логин                    |    Telegram-логин    |
|:---------:|:-------------------------------------------------:|:--------------------:|
| 1 |  **DashaDrozd**  |  **DrozdDasha** |

<a id=repo_collaborators pos=end></a>

### Текущая конфигурация Telegram-уведомлений

<a id=repo_config pos=begin></a>
|                 Тип уведомления                 |                      |
|-------------------------------------------------|:--------------------:|
|  Удаление **ветки**  |  :x:  |
|  Закрытие **PR**  |  :white_check_mark:  |
|  Слияние **PR**  |  :white_check_mark:  |
|  Открытие **PR**  |  :white_check_mark:  |
|  Переоткрытие **PR**  |  :white_check_mark:  |
|  Апрув **PR**  |  :white_check_mark:  |
|  Запрос изменений в **PR**  |  :white_check_mark:  |
|  Комментирование **PR**  |  :x:  |
|  Модификация **PR**  |  :white_check_mark:  |

<a id=repo_config pos=end></a>

----

## Установка git
- **Linux**: ([link](https://git-scm.com/download/linux))
  ```sh
  sudo apt-get install git
  ```

- **MacOS**: ([link](https://git-scm.com/download/mac))
  ```sh
  brew install git
  ```

- **Windows**:  [link](https://git-scm.com/download/win)

## Настройка git 

Первое, что вам следует сделать после установки `git` — указать ваше имя, адрес электронной почты и имя ветки по умолчанию. Это важно, потому что каждый коммит в `git` содержит эту информацию, и она включена в коммиты, передаваемые вами, и не может быть далее изменена:

```sh
git config --global user.name "Ivan Petrov"
git config --global user.email ivan.petrov@example.com
git config --global init.defaultBranch main
```
Если указан ключ `--global`, то настройки достаточно сделать только один раз, поскольку в этом случае `git` будет использовать эти данные для всего, что вы делаете в этой системе. Если для каких-то отдельных проектов вы хотите указать другое имя или электронную почту, можно выполнить эту же команду без параметра `--global` в каталоге с нужным проектом.

Проверить конфигурацию `git` можно с помощью:
```sh
git config --list
```

## Настройка SSH-ключей

Для успешного и безопасного соединения между локальной машиной и **GitHub** сервером необходимо правильно настроить **SSH-ключи**. 
(Оригинальная статья: [link](https://www.linkedin.com/pulse/how-use-multiple-github-accounts-macos-atish-maske))

### 1. Генерация

Сперва нужно создать и перейти в папку, которая будет хранить ключи (на **MacOS/Linux** SSH-ключи принято хранить в `~/.ssh`)

Генерируются ключи утилитой `ssh-keygen`, которая входит в пакет **OpenSSH** и устанавливается совместно с `git`:

```sh
ssh-keygen -t rsa -b 4096 -C "ivan.petrov@example.com"
# утилита попросит ввести имя файла и пароль (пароль можно пропустить)
```

Обязательно убедитесь, что именно этот **email** используется в вашем **GitHub-аккаунте** (перейдите в свой профиль -> **Settings** -> **Emails**)

При использовании нескольких **GitHub**-аккаунтов, ключи генерируются **для каждого отдельно**


### 2. Добавление ключа в GitHub-аккаунт

Перейдите в **свой профиль** -> **Settings** -> **SSH and GPG keys** -> **New SSH Key**

<img width="900" alt="image" src="https://github.com/Programming-Classrooms/Laboratory-Task-Template/assets/105939033/dd71f896-c6d6-43ac-91ce-cb2af4cdfb5c">

**Тип ключа**: Authentification key

**Значение ключа**: Скопировать из файла с **.pub** расширением (в созданной до этого папке)

### 3. Создание конфигурационного файла

Конфигурационный файл используется, чтобы указать различные **хосты** и **SSH-ключи** для каждой учетной записи **GitHub**. Для создания файла перейдите в ранее созданную директорию и воспользуйтесь любой утилитой редактирования текста (к примеру `nano` (**MacOS/Linux**) )

```sh
nano ~/.ssh/config
```

Файл нужно заполнить следующим содержимым:

```
# Account 1
Host github.com-IvanPetrov
  HostName github.com
  User git
  IdentityFile ~/.ssh/<название файла с ключом>

# Account 2
Host github.com-PetrIvanov
  HostName github.com
  User git
  IdentityFile ~/.ssh/<название файла с ключом>
```

Для самопроверки можно прописать:

```sh
ssh -T git@github.com-IvanPetrov
# Hi IvanPetrov! You've successfully authenticated, but GitHub does not provide shell access.
```

## Создание локальной копии репозитория (через SSH)

После настройки **SSH-ключей**, клонировать репозиторий можно через **SSH**

Для этого нужно использовать `git clone` с **SSH-ссылкой** (cоставить по примеру)

```sh
git clone git@github.com-IvanPetrov:<IvanPetrov>/<repository-name>.git
```

Если нужно скопировать репозиторий, который принадлежит чужому аккаунту или организации, ссылка будет выглядеть следующим образом:

```sh
git clone git@github.com-IvanPetrov:<Название организации или аккаунта>/<repository-name>.git
```

**ВНИМАНИЕ**: Ссылка составлена именно с указанием **Hostname** `git@github.com-IvanPetrov`, это указывает для `git`, какой именно аккаунт по будет использоваться для внесения изменений. Если скопировать ссылку в разделе **SSH** в кнопке **Code** главной страницы репозитория, **Hostname** будет выглядеть так: `git@github.com`, что может привести к ошибкам при данном способе использовании


## <a id="make-changes"></a>Внесение изменений

### <a id="make-changes-1"></a>1. Создание новой ветки

В каждом репозитории существует главная его ветка (**default branch**), которая используется для хранения стабильной и готовой к развертыванию версии вашего проекта. Главную ветку проекта принято называть `master` или `main`

Перед началом внесения изменений в репозиторий, хорошей практикой является создание новой ветки (которая позже будет cливаться c **main/master** через **Pull Request**)

В `git` двумя основными командами для работы с ветками являются `git checkout` (переключение между ветками) и `git branch` (действие над веткой)

При создании новой ветки удобно делать так:

```sh
git checkout -b <имя_новой_ветки> <существующая_ветка>
```
где флаг `-b` означает создание новой ветки (от существующей) и переключение на неё. Если вторым аргументом не указывать название сущесвующей ветки, то в качестве базовой ветки (**base branch**) будет использоваться текущая

Получить имя текущей ветки можно с помощью `git branch` (выведет список всех веток репозитория, текущая будет выделена символом `*`)

### 2. Коммиты

Для внесения изменений в `git`-репозиторий используются **коммиты**. Коммиты являются фундаментальным понятием в `git` и представляют собой снимки состояния проекта в определенный момент времени. Каждый коммит содержит информацию о внесенных изменениях, авторе коммита, времени создания и уникальном идентификаторе (хэше).

После редактирования элемента проекта, разницу нужно **закоммитить**. Для этого, изменения добавляются в **индекс** (область видимости `git`) следующим образом:
```sh
git add -A
```
Также можно использовать:
```sh
git add .
```
Для самопроверки можно прописать (покажет список измененных, добавленных или удаленных файлов)
```sh
git status
```

Теперь, можно сделать коммит:
```sh
git commit -m "Описание изменений"
```

При коммитировании, следуйте **3-ём основным правилам**:

- **Описательные сообщения коммитов:** Напишите информативное и содержательное сообщение коммита, которое четко описывает внесенные изменения. Избегайте слишком общих или запутанных описаний. Хорошее сообщение коммита помогает другим разработчикам и вам самим понять, какие изменения были внесены в код.
  
- **Маленькие и логические коммиты:** Разбивайте большие изменения на маленькие и логические коммиты. Каждый коммит должен вносить только одно изменение или решать одну задачу. Это позволяет легче просматривать историю изменений, откатывать или вносить изменения в отдельные коммиты.

- **Избегайте коммитирования незавершенной работы:** Коммитируйте только те изменения, которые полностью функциональны и прошли тестирование. Не коммитируйте незавершенный или испорченный код, так как это может затруднить работу других разработчиков и создать проблемы в будущем.


### 3. Отправка изменений на удалённый репозиторий (в GitHub)

Внесённые изменения нужно отправить на удалённый репозиторий. Это называется **push**, и выполняется при помощи команды:

```sh
git push origin <имя ветки с изменениями>
```

где `origin` обозначает удалённый репозиторий. `origin` автоматически инициализируется при `git clone`

Теперь, в удалённом репозитории появилась новая ветка с внесёнными изменениями

### 4. Создание Pull Request в GitHub

**Pull Request (PR)** - это механизм, который позволяет разработчикам предлагать свои изменения в основную ветку проекта.

Для создания **PR** нужно перейти в репозиторий проекта на **GitHub** и перейти в раздел **Branches**

<img width="564" alt="image" src="https://github.com/Programming-Classrooms/Laboratory-Task-Template/assets/105939033/126b96bb-c145-417e-b960-4b7d11efa063">

Найдите вашу ветку и нажмите на **New Pull Request**

<img width="1391" alt="image" src="https://github.com/Programming-Classrooms/Laboratory-Task-Template/assets/105939033/6ccd3fe8-8b56-4fda-8d14-8ad908282780">

Проверьте вносимые изменения, добавьте название и описание **PR**, подтвердите создание

**P.S.** **GitHub** также может предложить сделать **PR** сразу после того, как вы зайдёте в репозиторий проекта:

<img width="1032" alt="image" src="https://github.com/Programming-Classrooms/Laboratory-Task-Template/assets/105939033/5e2ec9db-f5be-487c-a3f3-c20d7291a1dc">

### 5. Работа с Code Review (ревью)

**Code review (ревью)** - это процесс, в ходе которого другой разработчик (**ревьюер**) анализирует ваш код с целью проверки его качества, соответствия стандартам кодирования, обнаружения потенциальных ошибок и предоставления обратной связи. **Ревьюер** делает комментарии к конкретным местам в вашем коде, а в конце делает общий вердикт, которых всего **3**: 
- **Запрошены изменения** (**Changes requsted**)
- **Прокомментировано** (**Commented**)
- **Одобрено** (**Approved**)

Сливать **новую ветку** с **основной**, как правило, разрешено только в случае, если ревьюер **одобрил** (поставил **approve**) вашему **PR**. 

Когда ревьюер делает комментарий к конкретному месту в коде, он автоматически открывает **Conversation** (обусуждение, диалог) - участок в **PR**, где происходит **обсуждение** конкретного вопроса по части кода. Пример классического **conversation**:

<img width="950" alt="image" src="https://github.com/Programming-Classrooms/Laboratory-Task-Template/assets/79075485/f54bc9f5-4984-43f9-bd79-d093da27a801">

**ВНИМАНИЕ**: Для внесения изменений по запросу ревьюера в уже существующий **PR** (т.е. в ветку этого **PR**) нужно сделать **push** в эту же ветку (см. шаги **2** и **3**)

Обычно, для того, чтобы показать исправления ревьюеру, в **conversation** вместе с пояснением пишут **хэш коммита**. Историю всех коммитов ветки можно просмотреть в главном разделе проекта, перейдя по **Commits**. Там же специальной кнопкой можно скопировать и их **хэш**, который **GitHub** уже сам превратит в ссылку на этот коммит при вставке в **conversation**.
 
<img width="1000" alt="image" src="https://github.com/Programming-Classrooms/Laboratory-Task-Template/assets/79075485/a033d4c2-1c2e-4223-9ad6-fcc0dbe6130c">

<img width="1000" alt="image" src="https://github.com/Programming-Classrooms/Laboratory-Task-Template/assets/79075485/b5bdcf1e-4981-47c7-b06f-d4e3541b7ad8">

Прежде чем слить ветку с `main`, в общем случае должно быть выполнено **4 условия**:

- **Ревьюер** поставил **апрув** (**Changes approved**)
- Все **диалоги** **зарезолвлены** (**Conversation** resolved)
- Все **проверки** успешно пройдены (**Checks** have passed)
- Нет **merge-конфликтов** с базовой веткой (**No merge-conflicts** with base branch)

Если **conversation** логически завершён, его **Резолвят** (разрешают, завершают) (кнопкой под самим **conversation**).

**Проверки** (**checks**) - автоматизированные действия, которые выполняются для оценки изменений, внесенных в ветку PR. **Checks** могут включать различные типы проверок, такие как тестирование кода, проверка стиля кодирования, статический анализ кода и т.п.

**Конфликты слияния** (**merge conflicts**) возникают в `git`, когда объединяемые ветки имеют различия в одном и том же месте файла или наборе файлов. Подробнее о конфликтах слияния в разделе **Что может пойти не так**

После того, как все **4 условия** выполнены Теперь, можете сливать вашу ветку с `main`. Это называется **Merge** (**мерж, вмержить ветку, смержить ветки**). Обычно, если дальнейшего развития ветки не планируется, ветка удаляется сразу же после **мержа**.

**Merge** и **удаление ветки** выполняются в **GitHub**. 

**Merge Pull Request:**

<img width="1000" alt="image" src="https://github.com/Programming-Classrooms/Laboratory-Task-Template/assets/105939033/19381b38-ddf7-45f7-98b0-0443e4906fc9">

**Delete branch:**

<img width="1000" alt="image" src="https://github.com/Programming-Classrooms/Laboratory-Task-Template/assets/79075485/977e131d-5e04-49e7-aa1c-1b083ed34e69">

На данном этапе в **GitHub-репозитории** ветки слиты, и все **коммиты новой ветки перемещены в** `main`, а **новая ветка удалена**. Однако в локальном репозитории таких изменений нет. Для того, чтобы они появились, нужно прописать:

```sh
git pull
```

`git pull` обновляет локальный репозиторий из удалённого (`origin`)

## Что может пойти не так

дополним из практики.
