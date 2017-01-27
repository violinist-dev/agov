core = 8.x
api = 2

defaults[projects][subdir] = "contrib"

; Contrib modules
projects[admin_toolbar][version] = 1.18
projects[layout_plugin][version] = 1.0-alpha23
projects[ctools][version] = 3.0-alpha27
projects[default_content][version] = '1.0-alpha3'
projects[twitter_block][version] = 2.1
projects[link_attributes][version] = '1.0-alpha3'
projects[pathauto][version] = '1.0-beta1'
projects[workbench_moderation][version] = '1.1'
projects[metatag][version] = '1.0-beta11'
projects[scheduled_updates][version] = '1.0-alpha5'
projects[simple_sitemap][version] = '2.7'
projects[video_embed_field][version] = '1.3'
projects[embed][version] = '1.0-rc3'
projects[media_entity][version] = '1.6'
projects[media_entity_image][version] = '1.2'
projects[entity][version] = '1.0-alpha3'
projects[entity_embed][version] = '1.0-beta2'
projects[entity_browser][version] = '1.0-beta2'
projects[inline_entity_form][version] = '1.0-beta1'
projects[token][version] = '1.0-beta2'
projects[fences][version] = '2.0-alpha1'
projects[media_entity_browser][version] = '1.0-beta2'
projects[better_normalizers][version] = '1.0-beta1'
projects[ds][version] = '2.6'
projects[panels][version] = 3.0-beta5

projects[page_manager][version] = '1.0-alpha24'
projects[page_manager][patch][] = https://www.drupal.org/files/issues/page_manager-block_content_contextual-2601004-14.patch


; Require dev release for the "password_policy_character_types" policy type.
projects[password_policy][type] = module
projects[password_policy][download][type] = git
projects[password_policy][download][url] = http://git.drupal.org/project/password_policy.git
projects[password_policy][download][branch] = 8.x-3.x
projects[password_policy][download][revision] = 896639711c174e45e62667613b163a571e64d926

; Development Modules
projects[config_devel][version] = '1.0-rc1'
projects[config_devel][subdir] = 'development'

; Themes
projects[agov_base][version] = '1.x-dev'
projects[agov_whitlam][version] = '1.2'
