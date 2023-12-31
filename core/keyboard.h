#pragma once

#include <unordered_map>
#include <QObject>
#include <QInternal>

enum class KeyAction {
  kMoveUp,
  kMoveDown,
  kMoveLeft,
  kMoveRight,
  kAction
};

class Keyboard: public QObject {
 public:
  Keyboard();

  void OnPress(Qt::Key);
  void OnRelease(Qt::Key);

  bool IsKeyPressed(KeyAction bind) const;

  void Block();
  void Unblock();
  bool IsBlocked() const;

 private:
  bool is_blocked_;

  std::unordered_map<Qt::Key, bool> is_key_pressed_;
  std::unordered_map<KeyAction, Qt::Key> bindings_;
};
