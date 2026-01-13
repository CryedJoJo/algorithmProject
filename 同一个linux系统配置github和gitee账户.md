可以的，而且**这是 Linux 下非常常见、也非常规范的做法** 👍
核心结论先给你：

> **同一台 Linux 主机上，可以同时关联 GitHub 和 Gitee，甚至多个不同账号，互不冲突。**
> 推荐方案：**SSH + 多 key + SSH config（~/.ssh/config）**
> ❌ 不推荐用 https + 频繁切账号（容易翻车）

下面我一步一步给你**工程级、可长期使用的标准方案**，你照着做即可。

---

## 一、总体思路（先理解）

Git 本身 **不关心账号**，它只关心：

* 用什么方式访问远程仓库（https / ssh）
* push 的时候用的 **认证凭据**

👉 我们做的事情只有三点：

1. **为 GitHub 和 Gitee 各生成一对 SSH key**
2. **通过 `~/.ssh/config` 指定：访问哪个域名，用哪把 key**
3. **每个项目设置对应的远程仓库地址**

---

## 二、为 GitHub / Gitee 生成不同的 SSH key

### 1️⃣ 进入 ssh 目录

```bash
cd ~/.ssh
```

---

### 2️⃣ 给 GitHub 生成 key

```bash
ssh-keygen -t ed25519 -C "github账号邮箱" -f ~/.ssh/id_ed25519_github
```

一路回车即可（是否设密码你自己决定）

生成文件：

```
id_ed25519_github
id_ed25519_github.pub
```

---

### 3️⃣ 给 Gitee 生成 key

```bash
ssh-keygen -t ed25519 -C "gitee账号邮箱" -f ~/.ssh/id_ed25519_gitee
```

生成：

```
id_ed25519_gitee
id_ed25519_gitee.pub
```

---

## 三、把公钥分别加到 GitHub / Gitee

### GitHub

```bash
cat ~/.ssh/id_ed25519_github.pub
```

* GitHub → Settings → SSH and GPG keys → New SSH key
* 粘贴进去

---

### Gitee

```bash
cat ~/.ssh/id_ed25519_gitee.pub
```

* Gitee → 设置 → SSH 公钥 → 新增
* 粘贴进去

---

## 四、配置 SSH config（关键步骤 ⭐）

编辑配置文件：

```bash
vim ~/.ssh/config
```

写入以下内容（**一字不改即可用**）：

```ssh
# GitHub
Host github.com
    HostName github.com
    User git
    IdentityFile ~/.ssh/id_ed25519_github

# Gitee
Host gitee.com
    HostName gitee.com
    User git
    IdentityFile ~/.ssh/id_ed25519_gitee
```

保存后设置权限（很重要）：

```bash
chmod 600 ~/.ssh/config
```

---

## 五、测试是否配置成功

### 测 GitHub

```bash
ssh -T git@github.com
```

成功会看到：

```
Hi xxx! You've successfully authenticated, but GitHub does not provide shell access.
```

---

### 测 Gitee

```bash
ssh -T git@gitee.com
```

成功会看到：

```
Hi xxx! You've successfully authenticated.
```

---

## 六、在同一台 Linux 上同时写 GitHub / Gitee 项目

### 1️⃣ clone GitHub 项目

```bash
git clone git@github.com:你的github用户名/项目名.git
```

### 2️⃣ clone Gitee 项目

```bash
git clone git@gitee.com:你的gitee用户名/项目名.git
```

👉 因为 SSH config 已经分流了 key
**你无需做任何额外操作，git 会自动用对的账号**

---

## 七、项目级用户信息（推荐做）

避免提交记录混乱（尤其你两个平台用户名不同）

### GitHub 项目里：

```bash
git config user.name "GitHubName"
git config user.email "github邮箱"
```

### Gitee 项目里：

```bash
git config user.name "GiteeName"
git config user.email "gitee邮箱"
```

👉 这是 **仓库级配置**，只对当前项目生效

查看：

```bash
git config --list
```

---

## 八、进阶：**同一个平台多个账号（比如 2 个 GitHub）**

如果你以后有：

* GitHub 账号 A
* GitHub 账号 B

也完全没问题，只需要：

```ssh
Host github-work
    HostName github.com
    User git
    IdentityFile ~/.ssh/id_ed25519_github_work

Host github-personal
    HostName github.com
    User git
    IdentityFile ~/.ssh/id_ed25519_github_personal
```

clone 时用：

```bash
git clone git@github-work:公司账号/项目.git
git clone git@github-personal:个人账号/项目.git
```

---

## 九、你这种情况的最佳实践总结

> ✅ **一台 Linux**
>
> ✅ **GitHub + Gitee**
>
> ✅ **同时开发**
>
> 👉 **SSH + 多 key + ssh config** 是标准、稳定、企业级方案

---

如果你愿意，我可以下一步帮你：

* 🔧 **直接给你一份“可复制粘贴”的完整脚本**
* 🧠 **解释 git 为啥不会混账号（原理级）**
* 🏗 **帮你设计 GitHub + Gitee 同步仓库方案（一推多仓）**

你更想继续哪一步？

