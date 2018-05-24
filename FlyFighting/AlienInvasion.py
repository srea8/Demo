import sys

import pygame
from Setting import Settings
from Ship import Ship
from pygame.sprite import Group
from Bullet import Bullet
from alien import Alien
from GameStats import GameStats
from Button import Button

def run_game():
    """初始化"""
    pygame.init()
    '''
    """设置背景和桌面"""
    screen = pygame.display.set_mode((1360,760))

    """设置背景颜色"""
    bg_color = (230,230,230)
    '''

    """设置标题"""
    pygame.display.set_caption("Aline Invasion")

    ai_setting = Settings()
    screen = pygame.display.set_mode((ai_setting.screen_width,ai_setting.screen_height))

    ship = Ship(screen)
    stats = GameStats(ai_setting)

    bullets = Group()
    bullet_one = Bullet(ai_setting, screen, ship)

    alien = Alien(ai_setting,screen)
    aliens = Group()
    alien.create_fleet(ai_setting,screen,aliens,ship)

    play_button = Button(ai_setting,screen,"Play!")

    while True:
        """游戏没有结束前，一直运行"""
        """控制飞船移动"""
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                sys.exit()

            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_RIGHT:
                    ship.move_right = True
                if event.key == pygame.K_LEFT:
                    ship.move_left = True
                if event.key == pygame.K_UP:
                    ship.move_up = True
                if event.key == pygame.K_DOWN:
                    ship.move_down = True
                if event.key == pygame.K_SPACE:
                    bullet_one.bullet_space = True
                if event.key == pygame.K_q:
                    sys.exit()
                if event.key == pygame.K_k:
                    stats.game_active = True
                    stats.ships_left = ai_setting.ship_limit

            elif event.type == pygame.KEYUP:
                if event.key == pygame.K_RIGHT:
                    ship.move_right = False
                if event.key == pygame.K_LEFT:
                    ship.move_left = False
                if event.key == pygame.K_UP:
                    ship.move_up = False
                if event.key == pygame.K_DOWN:
                    ship. move_down = False
                if event.key == pygame.K_SPACE:
                    bullet_one.bullet_space = False

            elif event.type == pygame.MOUSEBUTTONDOWN:
                if not stats.game_active:
                    mouse_x,mouse_y = pygame.mouse.get_pos()
                    play_button.check_paly_button(ai_setting,stats,play_button,mouse_x,mouse_y)




        """让最近绘制的屏幕可见"""
        screen.fill(ai_setting.bg_color)

        if stats.game_active:
            if stats.ships_left > 0 :
                bullet_one.fire_bullet(ai_setting, screen, ship, bullets)
                bullet_one.update_bullets(bullets, aliens)
                aliens.draw(screen)
                ship.update(ai_setting.ship_speed_factor)
                ship.blitme()
                alien.update_aliens(ai_setting, aliens, ship, screen, stats, bullets)
                if len(aliens) == 0:
                    bullets.empty()
                    alien.create_fleet(ai_setting, screen, aliens, ship)

        if not stats.game_active:
            pygame.mouse.set_visible(True)
            play_button.draw_button()
        """
        bullets.update()
        for bullet in bullets.sprites():
            bullet.draw_bullet()
        for bullet in bullets.copy():
            if bullet.rect.bottom <= 0:
                bullets.remove(bullet)
                """

        #alien.biltme()
        pygame.display.flip()

run_game()
